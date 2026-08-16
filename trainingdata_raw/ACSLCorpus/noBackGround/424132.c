#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int product;
    bool result;
    
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert ((a) * (b)) <= 100000000;
    
    product = a * b;
    
    //@ assert product == ((a) * (b));
    
    if (product % 2 == 0) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (product % 2 == 0);
    return result;
}
