#include <stdbool.h>

/*@
    requires 10 <= N <= 99;
    ensures \result == (N % 10 == 9 || (N / 10) % 10 == 9);
*/
bool func(unsigned long N) {
    unsigned long quotient_10;
    unsigned long remainder_10;
    unsigned long remainder_1;

    // Manual division and modulus implementation for N / 10
    quotient_10 = 0;
    remainder_10 = N;
    /*@
        loop invariant 10 <= N <= 99;
        loop invariant 0 <= quotient_10 <= N / 10;
        loop invariant remainder_10 == N - quotient_10 * 10;
        loop invariant remainder_10 < 100;
        loop assigns quotient_10, remainder_10;
    */
    while (remainder_10 >= 10) {
        quotient_10 += 1;
        remainder_10 -= 10;
    }

    // Manual modulus implementation for N % 10
    remainder_1 = N;
    /*@
        loop invariant 10 <= N <= 99;
        loop invariant 0 <= remainder_1 <= N;
        loop invariant remainder_1 == N - (N - remainder_1) / 10 * 10;
        loop invariant remainder_1 < 100;
        loop assigns remainder_1;
    */
    while (remainder_1 >= 10) {
        remainder_1 -= 10;
    }

    //@ assert remainder_1 == N % 10;
    //@ assert quotient_10 == N / 10;
    return quotient_10 == 9 || remainder_10 == 9 || remainder_1 == 9;
}
