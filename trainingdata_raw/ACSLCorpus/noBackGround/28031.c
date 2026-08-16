#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a * b % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int product;
    bool is_even;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert a * b <= 10000;
    
    product = a * b;
    is_even = (product % 2 == 0);
    
    return is_even;
}

/*@
    requires 1 <= n <= 100;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
*/
bool is_even(unsigned int n)
{
    bool ret;
    
    //@ assert 1 <= n <= 100;
    ret = (n % 2 == 0);
    
    return ret;
}
