# 🚢 Sea Battle

A desktop Sea Battle (Battleship-style) game written in **C++ with Qt**.
Built as the final project of the *Advanced Programming* course at
Isfahan University of Technology (IUT), Computer Engineering — 2024.

<!-- TODO: add a screenshot or GIF of the game, e.g.:
![Gameplay](images/screenshot.png)
-->

## ✨ Features

- Login screen and loading screen before the game starts
- Main game window designed with Qt Designer (`.ui` forms)
- Background music and custom images/fonts bundled as Qt resources
- <!-- TODO: add your real features, e.g. single-player vs. computer, ship placement, scoring -->

## 🛠 Tech stack

- C++
- Qt (Widgets, Qt Designer `.ui` forms, Qt resource system `.qrc`)
- qmake (`SeaBattle.pro`)

## ▶️ Build & run

1. Install [Qt](https://www.qt.io/download) and Qt Creator.
2. Clone the repo:
   ```bash
   git clone https://github.com/Maktulism/SEA-BATTLE.git
   ```
3. Open `SeaBattle.pro` in Qt Creator, choose a kit, and press **Run**.

Or from the command line:

```bash
qmake SeaBattle.pro
make
```

## 📁 Project structure

| File | Purpose |
|---|---|
| `main.cpp` | Application entry point |
| `loginscreen.*` | Login screen |
| `loadingscreen.*` | Loading screen |
| `mainwindow.*` | Main game window |
| `*.qrc`, `images/`, `fonts/`, `musics/` | Qt resources |

## 👤 Author

Seyed Abolfazl Hosseini — [GitHub](https://github.com/Maktulism)
