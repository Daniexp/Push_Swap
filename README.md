 # Push_Swap
 [![dexposit's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl2hrwxk3011709jppzcysckf/project/2527793)](https://github.com/JaeSeoKim/badge42)
## Description
In this project you have to sort some data (integers) on a stack with a limited set of instructions and in the fewest number of instructions. To be successful, you must learn some of the extensive algorithms and choose one than order 100 in < 700 and 500 in < 5500.
## How to use
### Compile and Execute the program
First of all you have to execute the makefile, I recommend use make bonus to compile the push_swap and the checker. Of course you have to be inside the repository.
```bash
make bonus clean;
```
You can pass the arguments (numbers to order) of this program with two differents ways.

The first one is write the numbers in different arguments of the program.
```bash
./push_swap 2 8 -22 -500 100;
```
Or you can put the numbers all in the same argument separates by spaces.
```bash
./push_swap "1 -2 50 -23 -20 100 47";
```
You can combine the options explaining before, but i think that it´s not really useful.
```bash
./push_swap "5 1 3" -6 "3 6 8 -11" 100 -200
```
The push_swap just print the sequence of moves that order the input.  So you have to use the checker to see if the push_swap really order or not.
I use the seq command, but you can use whatever you wan´t like some random number generator online or something like that.
```bash
arg=$(seq 0 99 | sort -R | xargs);
./push_swap $arg | ./checker $arg
```
### Inputs
### Outputs
