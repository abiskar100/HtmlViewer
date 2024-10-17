# HTML Document Viewer

## Overview

यो प्रोजेक्टले तपाइँलाई HTML डक्युमेन्टहरूलाई सजिलैसँग कमाण्ड लाइन इन्टरफेस (CLI) मार्फत हेर्न र काम गर्न अनुमति दिन्छ। यो परियोजना सरलताका लागि डिजाइन गरिएको हो, जसले तपाइँलाई न्यूनतम सेटअपमा छिटो HTML फाइलहरू लोड गर्न सक्षम बनाउँछ।

## Installation

HTML Viewer स्थापना गर्नका लागि तलका चरणहरू पालना गर्नुहोस्:

### Clone the Repository

```bash
git clone https://www.github.com/abiskar100/HtmlViewer.git
```
Compile the Program
```bash
g++ htmlviewer.cpp -o Lv
```

Move the Executable

कम्पाइल गरिएको एक्जिक्युटेबललाई /usr/local/bin/ मा सार्नुहोस् ताकि यो सबै ठाउँमा चल्न सकियोस्:

```bash

sudo mv Lv /usr/local/bin/
```

Make the Executable Usable

प्रोग्रामलाई चलाउन अनुमति दिनुहोस्:

```bash

sudo chmod +x /usr/local/bin/Lv
```

Ensure Port 8080 is Free

प्रोग्राम चलाउनु अघि, पोर्ट 8080 (वा तपाइँले प्रयोग गर्न लागेको कुनै पनि पोर्ट) पहिले नै प्रयोगमा छैन भनेर जाँच गर्नुहोस्। पोर्ट प्रयोगमा रहेको कुनै पनि प्रोसेसलाई मार्न तलका कमाण्डहरू चलाउनुहोस्:

```bash

sudo lsof -i :8080
sudo kill -9 <PID>  # यहाँ <PID> लाई पोर्ट 8080 प्रयोग गरिरहेको प्रोसेस ID मा परिवर्तन गर्नुहोस्
```

Prepare your Files

सुनिश्चित गर्नुहोस् कि प्रोजेक्ट डाइरेक्टरीमा मुख्य फाइलहरू छन्: index.html र style.css.
Run the Viewer

प्रोजेक्ट डाइरेक्टरीमा तलको कमाण्ड चलाउनुहोस्:

```bash
Lv
```

Access the Viewer

प्रोग्राम चलिरहेको बेला, वेब ब्राउजर खोल्नुहोस् र तलको URL मा जानुहोस्:

```bash
http://localhost:8080
```

यसले तपाइँको HTML डक्युमेन्ट लोड गर्नेछ जुन तपाइँ काम गर्दै हुनुहुन्छ। हाललाई, Lv कमाण्ड कुनै पनि तर्कहरू स्वीकार गर्दैन—यसलाई प्रोजेक्ट डाइरेक्टरीमा मात्र सीधा चलाउनुहोस्।

  > **NOTE:**  
> हाल Viewer ले फाइल वाचिंग सपोर्ट गर्दैन। यो फिचर भविष्यका रिलिजहरूमा थप्ने योजना छ।


Contributions Welcome!

यस परियोजनालाई सुधार गर्नको लागि तपाइँको चासोको लागि धन्यवाद। योगदान गर्नका लागि तलका चरणहरू पालना गर्नुहोस्:
Fork the Repository

सुरुमा यो रिपोजिटरीलाई तपाइँको GitHub खातामा फोर्क गर्नुहोस्।
Create a Feature Branch

तपाइँको फिचर वा फिक्सका लागि नयाँ ब्रान्च बनाउनुहोस्:

<<<<<<< HEAD
```bash
git checkout -b feature-branch
```
Make Your Changes
=======
5. Ensure Port 8080 is Free  
   Before running the program, make sure that port 8080 (or whichever port you're using) is not already occupied. To check and kill any processes using the port:
    ```bash
   sudo lsof -i :8080
   ```
   ```bash
   sudo kill -9 <PID>  # Replace <PID> with the process ID using port 8080
    ```
6. Prepare your files: Ensure the project directory contains the essential files: `index.html`, and `style.css`,
>>>>>>> 1f51a11927ffaa68075be1dae4ac786e53ff4170

तपाइँका सुधारहरू वा बग फिक्सहरू लागू गर्नुहोस्।
Commit Your Work

परिवर्तनहरूलाई स्पष्ट र संक्षिप्त सन्देश सहित कमिट गर्नुहोस्:

```bash
git commit -m "Add [feature/bug fix description]"
```

Push to GitHub

परिवर्तनहरू नयाँ ब्रान्चमा पुश गर्नुहोस्:

```bash
git push origin feature-branch
```

Submit a Pull Request

अन्तमा, Pull Request खोल्नुहोस् र हामी तपाइँका परिवर्तनहरूको समीक्षा गर्नेछौं।

धन्यवाद! 😊
