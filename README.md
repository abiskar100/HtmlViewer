# HTML Document Viewer

## Overview
This project allows you to view and work with your HTML documents efficiently through the command-line interface (CLI). It's designed for simplicity, ensuring you can quickly load your HTML files with minimal setup.

## Installation

Follow the steps below to install and use the HTML Viewer:


1. Clone the Repository  
     ```bash
   git clone https://www.github.com/abiskar100/HtmlViewer.git
    ```

2. Compile the Program  
    ```bash
   g++ htmlviewer.cpp -o Lv
    ```

3. Move the Executable  
   Move the compiled executable to `/usr/local/bin/` for global usage:
    ```bash
   sudo mv Lv /usr/local/bin/
   ```

4. Make the Executable Usable  
   Give the program execution rights:
    ```bash
   sudo chmod +x /usr/local/bin/Lv
    ```

5. Ensure Port 8080 is Free  
   Before running the program, make sure that port 8080 (or whichever port you're using) is not already occupied. To check and kill any processes using the port:
    ```bash
   sudo lsof -i :8080
   ```
   ```bash
   sudo kill -9 <PID>  # Replace <PID> with the process ID using port 8080
    ```
6. Prepare your files: Ensure the project directory contains the essential files: `index.html`, and `style.css`,

7. Run the Viewer: In the project directory, simply execute the following command:
    ```bash
   Lv
   ```

   After executing the `Lv` command, the program will start listening on port 8080.

8. Access the Viewer: Once the program is running, open your web browser and go to:
    ```bash
   http://localhost:8080
    ```

   This will load the HTML document you’re working on. No arguments are needed; the `Lv` command doesn’t accept any arguments at the moment—just run it directly from the terminal in your project directory.
   
    >**NOTE**
    >File watcher: Currently, the viewer does not support file watching. This >feature is planned for future releases.
    
    ## Contributions Welcome!

    We appreciate your interest in improving this project. To contribute, follow these simple steps:

9. **Fork the Repository**: Start by forking this repo to your GitHub account.
10.**Create a Feature Branch**: Create a new branch for your feature or fix.
   ```bash
   git checkout -b feature-branch
   ```
   
    11.**Make Your Changes**: Implement your enhancements or bug fixes.
    12.**Commit Your Work**: Commit the changes with a clear and concise message.

    ```bash
    git commit -m "Add [feature/bug fix description]"
    ```

    13.**Push to GitHub**: Push your changes to the new branch.

    ```bash
    git push origin feature-branch
    ```

    14.**Submit a Pull Request**: Finally, open a pull request and we'll review your changes.

    Thank you for helping make this project better! 😊


