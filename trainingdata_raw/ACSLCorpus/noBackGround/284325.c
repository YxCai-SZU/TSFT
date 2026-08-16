#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> 
            (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at top
    bool result;
    
    //@ assert a + b <= 200;
    
    if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
