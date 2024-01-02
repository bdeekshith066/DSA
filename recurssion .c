//DIRECT RECURSION

// factorial of n

#include<stdio.h>

long int multiplyNumbers(int n);

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Factorial of %d: %ld\n", n, multiplyNumbers(n));

    return 0;
}

long int multiplyNumbers(int n) {
    if (n >= 1)
        return n * multiplyNumbers(n - 1);
    else
        return 1;
}



// fibonnaci series

#include<stdio.h>

int fibonacci(int n);

int main() {
    int n;

    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}



// INDIRECT RECURSION

/*print odd number to n+1 and even number to n-1
say n=10 output (2,1,4,3,6,5,8,7,10,9)*/

#include <stdio.h>

void printNumbers(int n);

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Output: ");
    printNumbers(n);

    printf("\n");

    return 0;
}

void printNumbers(int n) {
    if (n <= 0) {
        return;
    }

    if (n % 2 == 0) {
        printf("%d ", n);
        printNumbers(n - 1);
    } else {
        printNumbers(n - 1);
        printf("%d ", n);
    }
}



// TOWER OF HANOI

#include <stdio.h>

void towers(int num, char frompeg, char topeg, char auxpeg);

int main() {
    int num;

    printf("Enter the number of disks: ");
    scanf("%d", &num);

    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towers(num, 'A', 'C', 'B'); // Assuming pegs are named A, B, and C

    return 0;
}

void towers(int num, char frompeg, char topeg, char auxpeg) {
    if (num == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", frompeg, topeg);
        return;
    }

    towers(num - 1, frompeg, auxpeg, topeg);
    printf("Move disk %d from peg %c to peg %c\n", num, frompeg, topeg);
    towers(num - 1, auxpeg, topeg, frompeg);
}

