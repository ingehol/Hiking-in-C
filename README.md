# Hiking project in C
This is a project written in C for registering hikes with name, length and height, where you'll receive a report in the terminal at the end of it.

## How to run the program: 
1. Traverse to the project's folder
2. Paste and run: gcc -o hiking hiking.c
3. Run: ./hiking

## A mini-guide for the program:
You will be promted with 3 separate inputs in this given order: Name, length, height.

At any input you can type END (must be caps) to end the program and retrieve the formatted report (in the terminal). This report will contain the total length and height of all the hikes, as well as printing out each of them individually

Only hikes where all 3 of the inputs have been registered will be saved, so if you end it before all 3 of the given values have been input, it won't be included (for instance if you type the name and length, but then write END at the height input, the hike won't be registered).