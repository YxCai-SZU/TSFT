#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ((a * b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned long long product;
    bool result;

    //@ assert a <= 10000;
    product = (unsigned long long)a * b;
    
    if (product % 2 == 0) {
        result = false;
    } else {
        result = true;
    }
    
    return result;
}
