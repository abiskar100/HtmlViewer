# HTML Document Viewer

## Overview
This project allows you to view and work with your HTML documents efficiently through the command-line interface (CLI). It's designed for simplicity, ensuring you can quickly load your HTML files with minimal setup.

## Installation

Follow the steps below to install and use the HTML Viewer:

1. **Clone the Repository**  
   Clone the project from GitHub:

   ```bash
   git clone https://www.github.com/abiskar100/htmlviewer
   ```

2. **Compile the Program**  
   Compile the `htmlviewer.cpp` file to create the executable. This step is critical to getting the viewer up and running:

   ```bash
   g++ htmlviewer.cpp -o Lv
   ```

3. **Move the Executable**  
   Move the compiled executable to `/usr/local/bin/` for global usage:

   ```bash
   sudo mv Lv /usr/local/bin/
   ```

4. **Make the Executable Usable**  
   Give the program execution rights:

   ```bash
   sudo chmod +x /usr/local/bin/Lv
   ```

---

## Usage

To use the HTML Viewer, ensure that you are in your project directory and that the necessary files are present. Follow the steps below:

1. **Prepare your files**: Ensure the project directory contains the essential files: `index.html`, `style.css`, and `script.js`.
   
2. **Run the Viewer**: In the project directory, simply execute the following command:

   ```bash
   Lv
   ```

3. **No arguments needed**: The `Lv` command doesn’t accept any arguments at the moment—just run it directly from the terminal in your project directory.

### Note
- **File watcher**: Currently, the viewer does not support file watching. This feature is planned for future releases.

---

## Contributing

Contributions are welcome! If you’d like to enhance this project, feel free to:
1. Fork the repository.
2. Create a feature branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

---

## License
This project is open source and available under the [MIT License](LICENSE).

---

Happy coding, and feel free to reach out with questions or suggestions!

