 # Push_Swap
 [![dexposit's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl2hrwxk3011709jppzcysckf/project/2527793)](https://github.com/JaeSeoKim/badge42)
## Description
In this project you have to sort some data (integers) on a stack with a limited set of instructions and in the fewest number of instructions. To be successful, you must learn some of the extensive algorithms and choose one than order 100 in < 700 and 500 in < 5500.
### Game Rules
 - You have two stacks, **a** and **b**.
 - At start:
   - In **a** you will have positive or negative numbers, never duplicate ones. It's really important that the first argument you pass is in the top of the stack **a**.
   - **b** will be empty.
 - You have to order the number of **a** in ascendent order.
 - To order the stack **a**, you have this available moves:

<div align="center">

| Output | Name | Description |
| :---: | :---: | :---:|
| sa | swap a | change the positions of the first and the second in a. |
| sb | swap b | same as sa but in a, only swap if they are at least 2 numbers. |
| ss | double swap | Do sa and sb at the same time. |
| pa | push a | take first in b and move it to the top of a. |
| pb | push b | take the first of a and move it to the top of b. |
| ra | rotate a | the first number in a is move it to the bottom of a. |
| rb | rotate b | the first number in b is move it to the bottom of b. |
| rr | double rotate | Do ra and rb at the same time. |
| rra | reverse rotate a | the last number in stack a is move it to the top. |
| rrb | reverse rotate b | the number in the bottom of b is move it to the top. |
| rrr | double reverse rotate | do rra and rrb at the same time. |

<div align="left">

### Inputs
The numbers can´t be duplicate or bigger than a integer. Of course all the inputs that are not numbers are not valid. There are some examples:
```bash
./push_swap "";
./push_swap "-";
./push_swap "2 -2 2";
./push_swap "-12s";
./push_swap "++2";
./push_swap 1000000000000;
./push_swap 3 -1 2 "     ";
```
### Outputs
#### Push Swap
- If some argument is incorrect the output will be `Error`.
- If the numbers are in order the push_swap will print `nothing`.
- In other case will print the moves, that order the numbers separete by `'\n'`.
#### Checker
- If exits some argument error, will print `Error`.
- If the moves printed by the push_swap doesn´t order the numbers in the correct order `KO`.
- If the push_swap order correctly `OK`.
### Implementation
 In this section we will see how my push_swap order the numbers, for all the people that are interested in implement something similar in their projects.
 
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
You can combine the options explaining before, but I think that it´s not really need it.
```bash
./push_swap "5 1 3" -6 "-3 6 8 -11" 100 -200;
```
The push_swap just print the sequence of moves that order the input.  So you have to use the checker to see if the push_swap really order or not.
I use the seq command, but you can use whatever you wan´t like some random number generator online or something like that.
```bash
arg=$(seq 0 99 | sort -R | xargs);
./push_swap $arg | ./checker $arg;
```
If you want to count the number of moves you can use the wc command.
```bash
arg=$(seq 0 499 | sort -R | xargs);
./push_swap $arg | wc -l;
```
