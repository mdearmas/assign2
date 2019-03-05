# assign2
CPSC 350, Assignment 2

STUDENT INFORMATION — Makenzie De Armas; ID: 2278709; dearm102@mail.chapman.edu

SOURCE FILES SUBMITTED — Doughnut.cpp // Doughnut.h // EnterSim.cpp // EnterSim.h // FileSim.cpp // FileSim.h // Gameboard.cpp // Gameboard.h // Gameplay.cpp // Gameplay.h // main.cpp // Makefile // Mirror.cpp // Mirror.h // README.md // Simulation.cpp // Simulation.h //

ERRORS — If the user enters a decimal  greater than 1 for rows/columns, the system reads the number before the decimal as the number and discards the decimal. // Changing the size of the console window during both PAUSE and PRESS ENTER modes can affect the overwriting feature that changes the board, which leaves remnants of the previous board above the latest generation. // When a Gameboard array is resized, the contents of the previous array are lost; this doesn’t affect the functionality, but it is a limitation should someone want to reuse this code.

RESOURCES — https://stackoverflow.com/questions/11347599/how-to-define-an-assignment-operator-outside-my-header-file-in-c (Defining an assignment operator for a new class.) // https://stackoverflow.com/questions/1238613/what-is-the-difference-between-the-dot-operator-and-in-c (Troubleshooting pointers.) // https://stackoverflow.com/questions/14997165/fastest-way-to-get-a-positive-modulo-in-c-c (Creating a positve modulo operation.) // https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1042856625&id=1043284385 (Making program wait for an [ENTER] keypress.) // https://stackoverflow.com/questions/45134217/c-go-back-a-line (Moving the cursor back a line.) // http://www.cplusplus.com/reference/thread/this_thread/sleep_for/ (Getting the program to pause for a second before proceeding, because System("Pause") is operating system specific and didn't work on MacOS.) // https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer (Guaranteeing that the user inputs an integer for things like rows and columns.) // http://life.geldmacher.net/ (Testing the assignment with preestablished Game of Life grids.) // http://www.cplusplus.com/doc/tutorial/ and https://en.cppreference.com/w/cpp for other assorted C++ information //

INSTRUCTIONS FOR RUNNING THE ASSIGNMENT — (1.) make all (2.) ./assignment2.exe (3.) Follow the program's prompts.
