#include <stdbool.h>

/*@
    predicate N_in_range(integer N) = 1 <= N <= 10000;
    predicate A_in_range(integer A) = 0 <= A <= 1000;
    predicate remainder_valid(integer N, integer remainder) =
        remainder >= 0 && remainder <= N &&
        (remainder == N || remainder % 500 == N % 500);
    predicate remainder_final(integer N, integer remainder) =
        remainder < 500 &&
        (remainder == N % 500 || remainder == N % 500 + 500);
*/

/*@
    requires N_in_range(N) && A_in_range(A);
    ensures \result == ((N % 500) <= A);
    assigns \nothing;
*/
bool func(int N, int A) {
    int remainder = N;
    
    /*@
        loop invariant N_in_range(N) && A_in_range(A);
        loop invariant remainder_valid(N, remainder);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 500) {
        //@ assert remainder >= 500;
        remainder -= 500;
    }
    
    /*@
        loop invariant N_in_range(N) && A_in_range(A);
        loop invariant remainder_final(N, remainder);
        loop assigns remainder;
        loop variant 500 + remainder;
    */
    while (remainder < 0) {
        //@ assert remainder < 0;
        remainder += 500;
    }
    
    //@ assert remainder == N % 500;
    return remainder <= A;
}

int main() {
    return 0;
}
