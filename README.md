<h1 align="center"><strong>Chinese Checkers Game</strong></h1>

A simple **Chinese Checkers** game developed on C++ -> **SFML** Graphics Library.

![board](/res/img/myBoard.png)

## **Contents**
- src     - main source code
    - Game - main application
    - Helpers - helper functions & constants
    - Checkers - game logic + drawing board
    - Slot - struct for individual circles on the board
    - Pch - pre-compiled header
- include - SFML + TGUI headers (TGUI still not used).
- lib     - SFML + TGUI + required std libs for windows.
- res     - misc files, images, fonts.

## **Building**
- Developed with MSVC (VS2019)
- Open SLN file in Visual Studio and run
- Updates coming soon for GCC and other compilers...

## **Playing**
1. Run Game.exe (or whatever extension)
2. "Lower half" of board plays first - click on any occuppied slot to select piece
3. Click on vacant slot to move piece (multiple steps possible when you jump by 2)
4. Turn system  
    a. If **SINGLE MOVE** or **NO LEGAL MOVES** -> turn switches automatically  
    b. Else -> press **ENTER KEY** when done with turn  
5. Repeat... (end of game not checked yet...)  
6. When a player has won, gameplay will stop -> end board will be displayed until window closed.

## **To-do**
- [ ] - LAN Multiplayer option  
- [ ] - GUI features (buttons, timers, etc)
