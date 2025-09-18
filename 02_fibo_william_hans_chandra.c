#include <stdio.h>
#include <time.h>

int fibonacciIterative(int n);
int fibonacciRecursive(int n);
int sumFibonacciIterative(int n);
int sumFibonacciRecursive(int n);

int main() {
    int number;
    struct timespec start, end;
    long iter_time, rec_time;

    printf("Enter a number: ");
    scanf("%d", &number);
    printf("\n");

    printf("Iterative\n");
    clock_gettime(CLOCK_MONOTONIC, &start);
    int iterativeResult = fibonacciIterative(number);
    int iterativeSum = sumFibonacciIterative(number);
    clock_gettime(CLOCK_MONOTONIC, &end);
    iter_time = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);

    printf("%dth Fibonacci = %d\n", number, iterativeResult);
    printf("Sum of Fibonacci until %dth term = %d\n", number, iterativeSum);
    printf("Iterative time: %ld nanoseconds\n\n", iter_time);

    printf("Recursive\n");
    clock_gettime(CLOCK_MONOTONIC, &start);
    int recursiveResult = fibonacciRecursive(number);
    int recursiveSum = sumFibonacciRecursive(number);
    clock_gettime(CLOCK_MONOTONIC, &end);
    rec_time = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);

    printf("%dth Fibonacci = %d\n", number, recursiveResult);
    printf("Sum of Fibonacci until %dth term = %d\n", number, recursiveSum);
    printf("Recursive time: %ld nanoseconds\n\n", rec_time);

    if (iter_time < rec_time) {
        printf("Iterative method is faster than recursive method by %ld nanoseconds\n",
               rec_time - iter_time);
    } else {
        printf("Recursive method is faster than iterative method by %ld nanoseconds\n",
               iter_time - rec_time);
    }

    return 0;
}

int fibonacciIterative(int n) {
    if (n <= 1) return n;

    int prev = 0, curr = 1, next;
    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int sumFibonacciIterative(int n) {
    if (n <= 0) return 0;

    int sum = 0;
    int prev = 0, curr = 1, next;

    sum = prev;
    if (n >= 1) sum += curr;

    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        sum += next;
        prev = curr;
        curr = next;
    }
    return sum;
}

int sumFibonacciRecursive(int n) {
    if (n <= 0) return 0;
    return fibonacciRecursive(n) + sumFibonacciRecursive(n - 1);
}
