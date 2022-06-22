 # Push_Swap
 [![dexposit's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl2hrwxk3011709jppzcysckf/project/2527793)](https://github.com/JaeSeoKim/badge42)
## Description
In this project you have to sort some data (integers) on a stack with a limited set of instructions and in the fewest number of instructions. To be successful, you must learn some of the extensive algorithms and choose one than order 100 in < 700 and 500 in < 5500.
## How to use
```bash
arg=$(seq 0 99 | sort -R | xargs);
./push_swap $arg | ./checker $arg
```
```bash
./push_swap 2 8 -22 -500 100;
```
