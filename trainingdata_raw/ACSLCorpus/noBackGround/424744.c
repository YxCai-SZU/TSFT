#include <stdbool.h>

/*@ requires 1 <= a <= 1000000000;
    ensures \result == (a % 2 == 0 && a % 6 == 0);
    assigns \nothing;
*/
bool func(unsigned long long a) {
    // Variable declarations at top
    bool result;
    
    //@ assert 1 <= a <= 1000000000;
    
    result = (a % 2 == 0) && (a % 6 == 0);
    
    return result;
}
