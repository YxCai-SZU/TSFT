#include <stdbool.h>

/*@
    requires ((1) <= (k) && (k) <= (100)) && ((1) <= (x) && (x) <= (100000));
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 500 * k <= 50000;
    //@ assert x <= 100000;
    result = (500 * k >= x);
    
    return result;
}

/*@
    requires ((1) <= (x) && (x) <= (100)) && ((1) <= (y) && (y) <= (100));
    ensures \result == ((x) * (y) / 2);
    assigns \nothing;
*/
unsigned int func2(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    unsigned int product;
    unsigned int result;
    
    //@ assert x * y <= 10000;
    product = x * y;
    result = product / 2;
    
    return result;
}
