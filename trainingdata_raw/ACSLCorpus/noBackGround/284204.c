#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (x / 100 * 100 <= x);
    assigns \nothing;
*/
bool func(unsigned int x) {
    unsigned int n;
    unsigned int no_carry;
    unsigned int ret;
    
    //@ assert (1 <= (x) <= 100000);
    
    n = x / 100;
    no_carry = x % 100;
    ret = n * 100 + no_carry;
    
    //@ assert ret == x;
    //@ assert ret <= x;
    
    return ret <= x;
}
