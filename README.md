# Grid Based Combat Game

## Objective 
A C++ program that implements a 'Walk-To' algorithm that allows a monster in a grid-based computer game to walk to the target (player's) position. 
The program loads a level (2D area), and monster's start position, from a text file. 
The program displays the level, the monster's start and target positions, and a list of moves the monster makes to reach the target. 
Each move is one of: north (up), east (right), south (down), and west (left).

## Legend
INPUT FILE: Loads the level using text characters to represent the terrain.
- An 'S' Position where the monster starts.
- A '.'  Open position; monster can walk through it at a move cost of 1.
- A '^'  Rocky position; monster can walk through it at a move cost of 2.
- A ':'  Rough position; monster can walk through it at a move cost of 4.
- A '#'  Wall; Impassible.
- A 'P'  Player starting position; target position monster will move towards. 
- A '*'  Open position; player goal position.
- 'A' and 'D' Positions where different types of monsters start.

OUTPUT: Text characters represent the terrain during output.
- A ' '   (space) Unoccupied open position. Space also used to represent start position after the monster (or player) has moved.
- A '^'   Rocky position.
- A ':'   Very rough position.
- A '*'   Player goal position.
- A '@'   Target position (player position).
- An 'M'  Monster's current position.

## Equipment 
Computer running Windows, MacOS or Linux, with an Intel or AMD based processor (x86 or x86-64) with administrator privileges. 
Linux (g++), Visual Studio, or XCode is recommended.
