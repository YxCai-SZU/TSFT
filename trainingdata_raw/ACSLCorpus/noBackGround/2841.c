#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ((a * b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at the top
    unsigned int product;
    bool result;

    //@ assert a * b <= 100000000;
    
    product = a * b;
    result = (product % 2) != 0;
    
    return result;
}
