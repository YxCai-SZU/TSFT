#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000000 && 0 <= (a) <= 1000000);
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(unsigned long n, unsigned long a) {
    bool result = false;
    unsigned long temp_n = n;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n % 500 == n % 500;
        loop assigns temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 500) {
        //@ assert temp_n % 500 == (temp_n - 500) % 500;
        temp_n -= 500;
    }

    //@ assert temp_n == n % 500;
    
    if (temp_n <= a) {
        result = true;
    }
    
    return result;
}
