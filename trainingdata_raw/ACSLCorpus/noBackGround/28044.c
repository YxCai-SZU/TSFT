#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000 &&
        1 <= (k) && (k) <= 1000000000);
    ensures \result == 0 ==> n % k == 0;
    ensures \result == 1 ==> n % k != 0;
    assigns \nothing;
*/
int func(unsigned int n, unsigned int k) {
    // Variable declarations at scope top
    unsigned int remainder;
    int result;

    //@ assert (1 <= (n) && (n) <= 1000000000 &&         1 <= (k) && (k) <= 1000000000);
    
    remainder = n % k;
    
    //@ assert 0 <= remainder && remainder <= n;
    
    if (remainder == 0) {
        //@ assert n % k == 0;
        result = 0;
    } else {
        //@ assert n % k != 0;
        result = 1;
    }
    
    return result;
}
