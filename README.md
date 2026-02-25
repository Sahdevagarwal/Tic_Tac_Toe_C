# 🎮 Tic-Tac-Toe (C Language)

A **console-based Tic-Tac-Toe game** written in **C** featuring multiple AI difficulty levels including an **unbeatable Minimax AI**.

This project demonstrates game design, modular programming, and basic Artificial Intelligence implementation using recursion.

---

## ✨ Features

✅ Player vs Player mode
✅ Player vs Computer mode
✅ Multiple difficulty levels:

* 🟢 Easy — Random moves
* 🟡 Medium — Smart blocking & winning logic
* 🔴 Hard — Minimax AI (Unbeatable)

✅ Clean board rendering
✅ Win & draw detection
✅ Modular bot system using function pointers
✅ Recursive AI decision making

---

## 🧠 Concepts Used

* Functions & Modular Design
* 2D Arrays
* Function Pointers
* Game Loop Architecture
* Recursion
* Backtracking
* Minimax Algorithm
* Basic Artificial Intelligence

---

## 🎲 How to Play

Board positions:

```id="a17392"
1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9
```

* Player **X** plays first.
* Enter the number corresponding to the position.
* Align three symbols in a row, column, or diagonal to win.

---

## 🤖 Difficulty Levels

### 🟢 Easy Mode

Computer chooses random empty positions.

### 🟡 Medium Mode

Computer:

1. Plays winning move if available
2. Blocks player’s winning move
3. Otherwise plays randomly

### 🔴 Hard Mode (Minimax AI)

* Simulates all future moves
* Chooses optimal outcome
* Cannot be defeated (best possible result is a draw)

---

## ⚙️ Compile & Run

### Compile

```bash id="a17393"
gcc main.c -o a.exe
```

### Run

```bash id="a17394"
./a.exe
```

(Windows users can run `a.exe` directly.)

---

## 📂 Project Structure

```id="a17395"
TicTacToe/
│
├── main.c
├── .gitignore
└── README.md
```

---

## 🚀 Learning Outcomes

This project helped practice:

* Game state management
* AI search algorithms
* Recursive problem solving
* Clean C project organization

---

## 👨‍💻 Author

**Sahdev Agarwal**

Aspiring AI/ML Engineer learning programming through hands-on projects.

---

⭐ If you like this project, consider giving it a star!
