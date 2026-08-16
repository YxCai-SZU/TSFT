#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == ((((a) * (b)) % 2 == 0 ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at top of scope
    unsigned long long product;
    bool result;
    
    //@ assert a > 0 && a <= 10000;
    product = a * b;
    
    //@ assert b > 0 && b <= 10000;
    
    //@ assert a * b <= 10000 * 10000;
    
    if (product == 0) {
        result = true;
    } else if (product % 2 == 0) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
