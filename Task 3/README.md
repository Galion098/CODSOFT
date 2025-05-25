# CODSOFT Task 3 - Tic Tac Toe Game

This is a C++ console-based **Tic Tac Toe game** that supports:
- Player vs Player mode
- Player vs AI mode using the **Minimax algorithm**

---

## Project Structure

```
CODSOFT/
└── Task 3/
    ├── tic_tac_toe_game.cpp   # Main C++ source code
    └── README.md              # This file
```

---

## Features

- 🎮 Play against a friend or an AI opponent
- 🤖 AI uses the Minimax algorithm for optimal moves
- ✅ Detects wins, losses, and draws
- 🧠 Simple input interface: row, column, symbol (e.g., `1 2 O`)

---

## How to Compile and Run

### Compile

Use a C++ compiler like `g++`:

```bash
g++ tic_tac_toe_game.cpp -o tic_tac_toe_game
```

### Run

```bash
./tic_tac_toe_game      # On Linux/Mac
tic_tac_toe_game.exe    # On Windows
```

---

## Gameplay Instructions

- At launch, you'll be asked if you want to play (`y/n`)
- Choose whether to play **against another person** or **against AI**
- Players take turns entering:
  - Row index (0–2)
  - Column index (0–2)
  - Their symbol: `O` or `X`

Example input:

```
1 2 O
```

- The board updates after every valid move
- Game ends when a player wins or all cells are filled (draw)

---

## Notes

- AI always plays as `X` and goes second
- Game uses a 3×3 matrix initialized with `-1` for empty cells
- No external libraries needed — runs in standard C++

---

Have fun playing or modifying the game!

