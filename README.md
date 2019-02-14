# Pong
Simple game

Sperasoft inspired me to create this game. I want to apply for their C++ engineer internship. Creation of this game helped me to repeat some C++ features. It was interesting and exciting and I got unforgettable feelings from playing in my own game. 

I wrote program using OOP. There is 4 classes in my program. Class Field describes proportions of gaming field and have function to draw it. Class Ball describes position of the ball and have function to change coordinates of ball. Class Gamer describes position of player and and have function to change coordinates of player. Class Judge describes scores of players and have functions to control movement of players and ball, define which of player is winner.

Program consist 3 files. Classes was written in file pch.h. You can find commentaries for class fields and class methods in this file. Function bodies of class methods was written in pch.cpp. Main program was written in file main.cpp. All these files you can find in folder ConsoleApplication1.

You can find executable file of the game in folder Debug. 

You can see simple menu when you start project. You need to enter number of menu item to choose it. To read instructions choose menu item number 1. Also you can read it below. 

Instructions:

Two players play in this game.
The aim of the game is to score the goal to the gate of another player.
One of the players win when his score reaches final score.
Default final score is 10. You can change it by selecting menu item number 3.

To start game press any button except 'B'
To quit game press 'B'.

Players can move their paddle to prevent goal of another player.
Left player can move his paddle up by pressing 'W' and down by pressing 'S'.
Right player can move his paddle up by pressing 'U' and down by pressing 'J'.

You can change proportion of gaming  field by selecting menu item number 2.
Recomended width of gaming field is more than 20 and less than 100.
Recomended length of gaming field is more than 6 and less than 20.
