#include <cstddef>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <cstring>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <sstream>

const std::string readFile(const std::string &filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Unable to open the file: " << filepath << std::endl;
        return "";  
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void createServer() {
    struct addrinfo hint, *res, *p;
    memset(&hint, 0, sizeof(hint));

    hint.ai_family = AF_UNSPEC;
    hint.ai_protocol = 0;
    hint.ai_socktype = SOCK_STREAM;
    hint.ai_flags = AI_PASSIVE;

    int resultfd = getaddrinfo(NULL, "8080", &hint, &res);
    if (resultfd != 0) {
        std::cerr << "ERROR: " << gai_strerror(resultfd) << std::endl;
        return;
    }

    int sockfd = -1;
    for (p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            std::cerr << "ERROR: Cannot create socket" << std::endl;
            continue;
        }
        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            std::cerr << "ERROR: Cannot bind the socket" << std::endl;
            close(sockfd);
            continue;
        }
        break;
    }

    if (p == NULL) {
        std::cerr << "ERROR: No results for addresses" << std::endl;
        freeaddrinfo(res);
        return;
    }

    if (listen(sockfd, 5) == -1) {
        std::cerr << "ERROR: Unable to listen" << std::endl;
        close(sockfd);
        return;
    }

    std::cout << "Listening on port 8080....." << std::endl;

    while (true) {
        struct sockaddr_storage client;
        socklen_t sofc = sizeof(client);
        int clientfd = accept(sockfd, (struct sockaddr*)&client, &sofc);
        if (clientfd == -1) {
            std::cerr << "ERROR: Client couldn't connect" << std::endl;
            continue;
        }

        char buffer[2048];
        int bytes_recv = recv(clientfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_recv < 0) {
            std::cerr << "ERROR: Unable to receive the message" << std::endl;
            close(clientfd);
            continue;
        }
        buffer[bytes_recv] = '\0';
        std::string request = buffer;

        std::string response;
        if (request.find("GET /style.css") != std::string::npos) {
            const std::string css_data = readFile("style.css");
            if (css_data.empty()) {
                response = "HTTP/1.1 404 Not Found\r\n";
                response += "Content-Length: 0\r\n";
                response += "Connection: close\r\n";
                response += "\r\n";
            } else {
                response = "HTTP/1.1 200 OK\r\n";
                response += "Content-Type: text/css\r\n";
                response += "Content-Length: " + std::to_string(css_data.size()) + "\r\n";
                response += "Connection: close\r\n";
                response += "\r\n";
                response += css_data;
            }
        } else if (request.find("GET /") != std::string::npos) {
            const std::string html_data = readFile("index.html");
            response = "HTTP/1.1 200 OK\r\n";
            response += "Content-Type: text/html\r\n";
            response += "Content-Length: " + std::to_string(html_data.size()) + "\r\n";
            response += "Connection: close\r\n";
            response += "\r\n";
            response += html_data;
        } else {
            response = "HTTP/1.1 404 Not Found\r\n";
            response += "Content-Length: 0\r\n";
            response += "Connection: close\r\n";
            response += "\r\n";
        }

        const char* msg = response.c_str();
        send(clientfd, msg, response.size(), 0);
        std::cout << "Response sent:" << response << std::endl;

        close(clientfd);
    }
    freeaddrinfo(res);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        createServer();
    } else {
        std::cout << "Usage: Lv" << std::endl;
        std::cout << "Make sure you have index.html and style.css in the current directory" << std::endl;
    }
}
