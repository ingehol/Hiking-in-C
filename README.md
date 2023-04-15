# Hiking project in C
This is a project written in C for registering hikes with name, length and height, where you'll receive a report in the terminal at the end of it.

## How to run the program (using the terminal):
We're going to use GCC (GNU Compiler Collection) to run the program
Type `gcc -v` to see if you have a complier installed. If you don't already have it, download it.
1. Traverse to the project's directory
2. Then run (based on operating system):
  Unix system: `gcc -o hiking hiking.c`
  Windows: `gcc -o hiking.exe hiking.c`
3. Run: 
  Unix system: `./hiking`
  Windows: `hiking.exe`

## A mini-guide for the program:
You will be promted with 3 separate inputs in this given order: Name, length, height.

At any input you can type END (must be caps) to end the program and retrieve the formatted report (in the terminal). This report will contain the total length and height of all the hikes, as well as printing out each of them individually

Only hikes where all 3 of the inputs have been registered will be saved, so if you end it before all 3 of the given values have been input, it won't be included (for instance if you type the name and length, but then write END at the height input, the hike won't be registered).
