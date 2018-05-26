# Filler


• In this game, two players fight each other. They play one after the other.


• The goal is to collect as many points as possible by placing the highest number of
pieces on the the game board.


• The board is defined by X columns and N lines, it will then become X*N cells.


• At the beginning of each turn, you will receive your game piece.


• A game piece is defined by X columns and N lines, so it will be X*N cells. Inside
each game piece, will be included a shape of one or many cells.


• To be able to place a piece on the board, it is mandatory that one, and only one
cell of the shape (in your piece) covers the cell of a shape placed previously (your
territory).


• The shape must not exceed the dimensions of the board


• When the game starts, the board already contains one shape.


• The game stops at the first error: either when a game piece cannot be placed
anymore or it has been wrongly placed.


__I made my player which calls "opavliuk.filler" and like a bonus, I made visualizer.__

In directory "resources" there are:

- the main program, virtual machine, which calls "filler_vm"!

- different players!

- some maps for game!

__Usage:__

__./filler_vm -p1 [name player].filler -p2 [name player].filler -f [map] | ./visualizer__
