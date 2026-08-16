#include <stdbool.h>

/*@
    requires 10 <= N && N <= 99;
    ensures \result == (N / 10 == 9 || N % 10 == 9);
*/
bool func(int N) {
    int quotient = 0;
    int remainder = N;
    int divisor = 10;
    
    //@ assert (10 <= (N) && (N) <= 99);
    //@ assert remainder == N;
    //@ assert divisor == 10;
    
    /*@
        loop invariant 10 <= N && N <= 99;
        loop invariant 0 <= quotient && quotient <= N / 10;
        loop invariant remainder == N - quotient * 10;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    
    if (remainder < 0) {
        quotient -= 1;
        remainder += divisor;
    }
    
    //@ assert 0 <= quotient * 10 && quotient * 10 <= 99 * 10;
    //@ assert quotient == N / 10;
    //@ assert remainder == N % 10;
    
    return quotient == 9 || remainder == 9;
}

int main() {
    return 0;
}
