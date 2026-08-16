#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (x / 100 * 100 <= x);
    assigns \nothing;
*/
bool func(unsigned int x) {
    unsigned int n;
    unsigned int b;
    unsigned int a;
    
    n = x / 100;
    b = x % 100;
    a = n * 100 + b;
    
    //@ assert a == x;
    //@ assert n * 100 <= x;
    
    return a <= x;
}
