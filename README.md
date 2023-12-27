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
## Issue
- The code seems to run with $O(n^2)$... When running $10000!$, it takes 10 min.

- Current multiplcation approach... and there might be a faster approach, or improvement in the implementation
  ```
  Step1:
                      222
                  *    11
                 ========
                     2220----> Get these values
                      222---->

  Step2:
                     2220
       Add Prefix--->0222

  Step3:
                     2220
                  +  0222
                  =======
      Sum the value  2442
        

