# 🖼️ Object Detection in Binary Images

> Data Structures and Algorithms project focused on detecting objects in binary images using **Breadth-First Search (BFS)** and identifying whether the image contains a frame.

---

## 📌 Project Overview

This project processes a binary image represented as a matrix of:

- `0` → black pixel  
- `1` → white pixel  

The system analyzes the matrix to:

- Detect and count connected objects within the image  
- Determine whether the image contains a surrounding frame  

The implementation applies graph traversal techniques using **Breadth-First Search (BFS)** over a 2D matrix structure.

---

## ⚙️ Features

| Feature | Description |
|---|---|
| 🔍 **Object Detection** | Identifies connected components within the image |
| 📊 **Object Counting** | Counts the total number of detected objects |
| 🖼️ **Frame Detection** | Verifies whether the image borders form a valid frame |
| 📂 **File-Based Input** | Loads image data from an external `.txt` file |

---

## 🏗️ Project Structure

```text
📁 ObjectDetection/
├── 📄 main.cpp        # Complete source code (FunctionBFS class + main)
├── 📄 imagen.txt      # Example input matrix
└── 📄 Parcial3.exe    # Compiled Windows executable
```

---

## 🚀 How to Run

### Requirements
- Windows environment (for `detector.exe`)  
- Or a C++ compiler such as `g++` to compile manually  

### Execution Steps

1. Download or clone the repository  
2. Make sure `imagen.txt` is located in the same folder as `detector.exe`  
3. Run `detector.exe` from the terminal or by double-clicking it  
4. When prompted, enter the file name:

```text
imagen.txt
```

---

## 📄 Input File Format

The input file must contain a matrix written in **Python-style list format** using brackets and commas.

### Example

```text
[
[0, 0, 0, 0, 0],
[0, 1, 1, 0, 0],
[0, 1, 1, 0, 0],
[0, 0, 0, 0, 0]
]
```

---

## 🧠 Algorithm Explanation

### 🔹 Object Counting using BFS

The system uses **Breadth-First Search (BFS)** to identify connected components in the matrix.

Connectivity is based on **4-directional neighbors**:
- Up  
- Down  
- Left  
- Right  

Each connected region of `1`s is considered a separate object.

---

### 🔹 Frame Detection

The program checks whether all border pixels are `0` by validating:

- First row  
- Last row  
- First column  
- Last column  

If every border value is `0`, the image is considered to contain a valid frame.

---

## 📊 Concepts Applied

- Breadth-First Search (BFS)  
- Matrix traversal  
- Connected components  
- Queue-based exploration  
- Graph representation in grids  

---

## 🛠️ Compilation

To compile the project manually using `g++`:

```bash
g++ main.cpp -o detector
```

---

## 👨‍💻 Author

**Jeronimo Jaramillo Agudelo**  

Data Structures and Algorithms — 2026
