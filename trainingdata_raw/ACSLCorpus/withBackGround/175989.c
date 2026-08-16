#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate is_odd(integer x) = x % 2 != 0;
*/

/*@
    requires x <= 65535;
    ensures \result == (x % 2 == 0);
    assigns \nothing;
*/
bool even(unsigned int x)
{
    bool result;
    //@ assert x % 2 == 0 || x % 2 == 1;
    result = (x % 2 == 0);
    //@ assert result == (x % 2 == 0);
    return result;
}

/*@
    requires x <= 65535;
    ensures \result == (x % 2 != 0);
    assigns \nothing;
*/
bool odd(unsigned int x)
{
    bool result;
    //@ assert x % 2 == 0 || x % 2 == 1;
    result = (x % 2 != 0);
    //@ assert result == (x % 2 != 0);
    return result;
}

int main()
{
    bool n;
    bool m;
    
    n = even(50);
    //@ assert n == true;
    m = odd(51);
    //@ assert m == true;
    
    return 0;
}
