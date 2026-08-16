#include <stdbool.h>

/*@ requires ((1) <= (a) && (a) <= (100));
    requires ((1) <= (b) && (b) <= (100));
    requires ((1) <= (x) && (x) <= (200));
    ensures \result == (x >= a && x <= a + b);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= x && x <= 200;
    
    result = (x >= a && x <= a + b);
    return result;
}
