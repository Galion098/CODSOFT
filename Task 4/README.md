# CODSOFT Task 2 - To-Do List Application

This is a simple console-based **To-Do List application** developed using **C++**.  
It allows users to add tasks, view them, update their status, and delete them.  
Tasks are stored persistently in a text file (`to_do_list.txt`).

---

## Project Structure

```
CODSOFT/
└── Task 2/
    ├── README.md           # This documentation file
    ├── to_do_list.txt      # Text file used for task storage
    └── to_do_list.cpp      # Main C++ source file
```

---

## Features

- ✅ Add a new task with a status (`complete` or `incomplete`)
- 📋 View all tasks with their statuses
- 🛠️ Update the status of a task to `complete`
- ❌ Delete a task from the list
- 💾 All tasks are saved in `to_do_list.txt` for persistence

---

## How to Compile and Run

### 1. Compile

Use a C++ compiler like `g++`:

```bash
g++ to_do_list.cpp -o to_do_list
```

### 2. Run

```bash
./to_do_list      # On Linux/Mac
to_do_list.exe    # On Windows
```

---

## Example `to_do_list.txt` content

```
College Project
incomplete
Doing Codsoft
complete
Sleeping
incomplete
Leetcode
complete
```

Each task is saved with its status on the next line.

---

## Notes

- File handling is done using `fstream`.
- If `to_do_list.txt` does not exist, it will be created automatically.
- The program uses a `temp.txt` file internally while updating or deleting tasks, then renames it back.

---

Feel free to modify or extend this project!

