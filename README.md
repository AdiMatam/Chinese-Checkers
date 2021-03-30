<h1 align="center"><strong>Chinese Checkers Game</strong></h1>

A simple **Chinese Checkers** game developed on C++ -> **SFML** Graphics Library.

![board](/res/img/myBoard.png)

## **Contents**
- #### src     - main source code
    - Game - main application
    - Helpers - helper functions & constants
    - Checkers - game logic + drawing board
    - Slot - struct for individual circles on the board
    - Pch - pre-compiled header
- #### include - SFML + TGUI headers (TGUI still not used).
- #### lib     - SFML + TGUI + required std libs for windows.
- #### res     - misc files, images, fonts.

## **Building**
- Developed with MinGW GCC
- MinGW - ```make``` in terminal.
- Updates coming soon for other compilers...

## **Playing**
1. Run Game.exe (or whatever extension)
2. "Lower half" of board plays first - click on any occuppied slot.
3. This selects piece; then, click on un-occuppied slot to move piece (multiple steps still not working...)
4. Turn switches, "Upper half" of board plays now.

## **To-do**
- [ ] - LAN Multiplayer option  
- [ ] - GUI features (buttons, timers, etc)
