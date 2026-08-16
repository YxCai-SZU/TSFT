#include <stdbool.h>

/*@
    predicate is_valid_range(integer N) = 100 <= N <= 999;

    logic integer unsigned_of(integer N) = (N < 0) ? -N : N;

    logic integer div_100_result(integer N) = N / 100;
    logic integer div_10_result(integer N) = (N / 10) % 10;
    logic integer mod_10_result(integer N) = N % 10;

    predicate has_seven(integer N) = 
        div_100_result(N) == 7 || 
        div_10_result(N) == 7 || 
        mod_10_result(N) == 7;
*/

/*@
    requires is_valid_range(N);
    ensures \result == 1 <==> has_seven(N);
    assigns \nothing;
*/
bool func(int N) {
    unsigned int N_unsigned;
    unsigned int div_100 = 0;
    unsigned int temp;
    unsigned int div_10 = 0;
    
    // Convert to unsigned
    if (N < 0) {
        N_unsigned = (unsigned int)(-N);
    } else {
        N_unsigned = (unsigned int)N;
    }
    
    temp = N_unsigned;
    
    // First loop: compute N_unsigned / 100
    /*@
        loop invariant 0 <= temp <= N_unsigned;
        loop invariant div_100 <= N_unsigned / 100;
        loop invariant temp == N_unsigned - 100 * div_100;
        loop assigns temp, div_100;
        loop variant temp;
    */
    while (temp >= 100) {
        temp -= 100;
        div_100 += 1;
    }
    
    // Second loop: compute (N_unsigned - 100*div_100) / 10
    /*@
        loop invariant 0 <= temp <= N_unsigned;
        loop invariant div_10 <= (N_unsigned - 100 * div_100) / 10;
        loop invariant temp == N_unsigned - 100 * div_100 - 10 * div_10;
        loop assigns temp, div_10;
        loop variant temp;
    */
    while (temp >= 10) {
        temp -= 10;
        div_10 += 1;
    }
    
    //@ assert div_100 == N_unsigned / 100;
    //@ assert div_10 == (N_unsigned - 100 * div_100) / 10;
    //@ assert temp == N_unsigned % 10;
    
    return (div_100 == 7) || (div_10 == 7) || (temp == 7);
}

int main() {
    return 0;
}
