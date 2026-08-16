#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (x >= 2000 || x % 2000 != 0);
    assigns \nothing;
*/
bool func(unsigned long long x) {
    unsigned long long n;
    unsigned long long a;
    
    n = x / 2000;
    a = x % 2000;
    
    //@ assert n * 2000 + a == x;
    
    return n >= 1 || a != 0;
}
