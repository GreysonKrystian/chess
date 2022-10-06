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
Project was tested with Qt version 5.15.2

### Tutorial for building project using Visual Studio
  
  1. Download Qt VS Tools as extension for Visual Studio
  2. Download Qt (msv2019) version from Qt website
  3. In Qt versions tab in Qt VS Tools add new Qt version (specify path to bin with qmake file.
  
# Project description

[(Back to top)](#table-of-contents)

It was university project where we worked in groups of 3. We created chess game where UI was created using [QT](https://www.qt.io).
Player can choose to play with other player (on same machine) or with AI. AI performs random moves, but captures figures when he can and defends king when 
king is checked. After the game player can replay whole game and save history of moves to file.

Main clases of project:
- Game Engine
- Board
- chess figures
- main GUI
- tests classes

*Game Engine* -
*Board* - 
*chess figures* - 
*main GUI* - 


# Possible future improvements

[(Back to top)](#table-of-contents)

- add more tests - the game can still contain bugs because it was not tested enough
- the game AI is very primitive - the chess lack AI to compete with, solution for this can be better alghoritm such as Minimax
- better UI - The Qt design could be improved.
- add menu - there are no menu at the moment, the options which include resolution and difficulty could be added.


# Screenshots

[(Back to top)](#table-of-contents)

<strong>MENU</strong>:
<br>
<p align="center" width="100%">
<br>
<br>
</p>

<strong>GAMEPLAY</strong>:
<br>
<p align="center" width="100%">
 <br>
 <br>
<br>
<br>
<br>
<br>
</p>





# License

[(Back to top)](#table-of-contents)


The MIT License (MIT) 2022 - [Krystian Grela](https://github.com/GreysonKrystian/), Aleksander Woś, Adam Wróblewski. Please have a look at the [LICENSE.md](LICENSE.md) for more details.
We are NOT authors of gifs and chess figures images which are included in this project. 
