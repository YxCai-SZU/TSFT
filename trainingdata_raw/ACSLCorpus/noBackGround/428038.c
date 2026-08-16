#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 1 <= m <= 10000;
    ensures \result == ((n * m) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    unsigned int product;
    bool is_even;
    bool result;

    //@ assert n <= 10000 && m <= 10000;
    //@ assert ((n) * (m)) <= 100000000;

    product = n * m;
    is_even = (product % 2 == 0);
    
    //@ assert product == n * m;
    //@ assert is_even == (product % 2 == 0);
    
    result = !is_even;
    //@ assert result == (product % 2 != 0);
    return result;
}
