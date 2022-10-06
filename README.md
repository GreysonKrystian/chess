# Chess

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Qt](https://img.shields.io/badge/Qt-%23217346.svg?style=for-the-badge&logo=Qt&logoColor=white)

# Table of contents

- [Requirements](#requirements)
- [Project description](#project-description)
- [Possible future improvements](#possible-future-improvements)
- [Screenshots](#screenshots)
- [License](#license)

# Requirements

Project should be build in C++. Project requires Qt to work. It can be downloaded from [here](https://www.qt.io).
Project was tested with Qt version 5.15.2 .

### Tutorial for building project using Visual Studio
  
  1. Download Qt VS Tools as extension for Visual Studio
  2. Download Qt (msv2019) version from Qt website
  3. In Qt versions tab in Qt VS Tools add new Qt version (specify path to bin with qmake file.
  
# Project description

[(Back to top)](#table-of-contents)

It was university project where we worked in groups of 3. We created chess game where UI was created using [QT](https://www.qt.io). The only language of the game is Polish. Player can choose to play with other player (on same machine) or with AI. AI performs random moves, but captures figures when he can and defends king when 
king is checked. After the game player can replay whole game and save history of moves to file. 

Main clases of project:
- Game Engine
- Board
- chess figures
- main GUI
- tests classes

*Game Engine* - supervises current state of the game, contains methods responsible for capturing figures, checks if king is checked, contains chess mechanics such as castling. Moreover the class contains primitive chess AI.
*Board* - checks where figures can move and what moves are currently legal.
*Chess figures* - manages creating, deletign and positioning figures on the board.
*Main GUI* - main QT class which is responsible for displaying the whole game and capturing user inputs.


# Possible future improvements

[(Back to top)](#table-of-contents)

- add more tests - the game can still contain bugs because it was not tested enough
- the game AI is very primitive - the chess lack AI to compete with, solution for this can be better alghoritm such as Minimax
- better UI - The Qt design could be improved.
- add menu - there are no menu real at the moment, the options which include resolution and difficulty could be added.
- improve game mechanics - the game lacks some basic chess mechanics like the pawn promotion for other figure than queen or en Passant.

# Screenshots

[(Back to top)](#table-of-contents)

<strong>MENU</strong>:
<br>
<p align="center" width="100%">
<img alt="Screenshot from menu" src="https://raw.github.com/GreysonKrystian/chess/master/Screenshots/Menu_1.png" width=800 height= auto>
<br>
<br>
<img alt="Screenshot from menu" src="https://raw.github.com/GreysonKrystian/chess/master/Screenshots/Menu_2.png" width=800 height= auto>
</p>

<strong>GAMEPLAY</strong>:
<br>
<p align="center" width="100%">
<img alt="Screenshot from menu" src="https://raw.github.com/GreysonKrystian/chess/master/Screenshots/Gameplay.png" width=800 height= auto>
 <br>
 <br>
 <img alt="Screenshot from menu" src="https://raw.github.com/GreysonKrystian/chess/master/Screenshots/End.png" width=800 height= auto>
<br>
<br>
<img alt="Screenshot from menu" src="https://raw.github.com/GreysonKrystian/chess/master/Screenshots/Replay.png" width=800 height= auto>
</p>
<br>

# License

[(Back to top)](#table-of-contents)


The MIT License (MIT) 2022 - [Krystian Grela](https://github.com/GreysonKrystian/), Aleksander Woś, Adam Wróblewski. Please have a look at the [LICENSE.md](LICENSE.md) for more details.
We are NOT authors of gifs and chess figures images which are included in this project. 
