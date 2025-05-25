# CODSOFT Calculator Project

This repository contains a basic calculator project developed using:

- **C++** for the core calculation logic  
- **Python Tkinter** for the graphical user interface (GUI)

---



## Project Structure

```
Task 2/                   # Folder for Task 2 files
├── README.md             # this file
├── calculator_gui.py     # Python Tkinter GUI
└── calculator.cpp        # C++ core logic
```

---

## How to Run

### Compiling the C++ code to create calc.dll

1. Compile the C++ code using a compiler like `g++`:

   ```bash
    g++ -shared -o calc.dll calculator.cpp
   ```

---

### Running the Python Tkinter GUI

Make sure you have Python installed (version 3.x recommended).

1. Run the Python GUI script:

   ```bash
   python gui.py
   ```

2. The Tkinter window will open allowing you to perform calculations via the GUI.

---

## Notes

- The Python GUI is linked to the C++ logic for enhanced functionality (optional).
- No additional dependencies are required other than Python's standard Tkinter library.
