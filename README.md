# Factorial
A program calculate factorial less likely fuck up by overflow
## Implementation
vector store each digit of a integer and do the calculation using recursion.
## Compile
```
g++ helper_function.hpp factorial.cpp -o factorial
```
## Usecase
```
./factorial
```
and input the non-negative integer. 

## issue
- May overflow when input >$2^{31}-1$ digits integer (Using signed int + the flat function run after the for loop)
- 10000! takes 2.5 minutes to calculate
