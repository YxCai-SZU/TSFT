#include <stdbool.h>

/*@ predicate is_nine_in_tens(integer n) = (n / 10) % 10 == 9; */
/*@ predicate is_nine_in_units(integer n) = n % 10 == 9; */
/*@ predicate has_nine(integer n) = is_nine_in_tens(n) || is_nine_in_units(n); */

/*@
    requires 10 <= n <= 99;
    ensures \result == 1 <==> has_nine(n);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    bool res = false;
    
    //@ assert 10 <= n <= 99;
    
    if ((n / 10) % 10 == 9 || (n % 10) == 9)
    {
        res = true;
    }
    
    //@ assert res == 1 <==> has_nine(n);
    
    return res;
}
