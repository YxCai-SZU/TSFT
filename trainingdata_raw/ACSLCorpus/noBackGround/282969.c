#include <stdbool.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> ((n) % 2 == 0);
    ensures \result == 1 ==> ((n) % 2 != 0);
*/
int func(long n) {
    long abs_n;
    bool is_even_bool;
    
    // Calculate absolute value
    if (n < 0) {
        abs_n = -n;
    } else {
        abs_n = n;
    }
    
    // Manual modulus operation
    /*@
        loop invariant 0 <= abs_n <= 100000;
        loop invariant 1 <= n <= 100000;
        loop invariant abs_n % 2 == n % 2;
        loop assigns abs_n;
        loop variant abs_n;
    */
    while (abs_n >= 2) {
        abs_n -= 2;
    }
    
    is_even_bool = (abs_n == 0);
    
    if (is_even_bool) {
        //@ assert ((n) % 2 == 0);
        return 0;
    } else {
        //@ assert ((n) % 2 != 0);
        return 1;
    }
}

int main() {
    return 0;
}
