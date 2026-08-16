#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (x) <= 200);
    ensures \result == (x >= a && x <= a + b);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x) {
    unsigned long long c;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (x) <= 200);
    
    c = a + b;
    
    //@ assert c == ((a) + (b));
    
    if (x < a || x > c) {
        return false;
    } else {
        return true;
    }
}
