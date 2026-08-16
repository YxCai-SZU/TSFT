#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000);
    ensures \result == ((a * b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b) {
    // Variable declarations at top of scope
    unsigned long long c;
    bool result;

    //@ assert (1 <= (a) && (a) <= 10000);
    //@ assert (1 <= (b) && (b) <= 10000);
    //@ assert ((a) * (b) <= 10000 * 10000);
    
    c = a * b;
    
    //@ assert ((c) % 2 == ((a) * (b)) % 2);
    //@ assert (1 * 1 <= (a) * (b));
    
    result = (c % 2 == 0);
    return result;
}
