#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 10 <= n && n <= 99;

    logic integer condition_holds(integer n) = n % 10 == 9 || n >= 90 ? 1 : 0;

    lemma mod_property: \forall integer n; is_valid_range(n) ==> 
        (n % 10 == 9 || n >= 90) == ((unsigned)n % 10 == 9 || (unsigned)n >= 90);
*/

/*@
    requires is_valid_range(n);
    ensures \result == (condition_holds(n) == 1);
    assigns \nothing;
*/
bool func(int n)
{
    unsigned int n_unsigned;
    bool result;

    //@ assert is_valid_range(n);
    n_unsigned = (unsigned int)n;

    if (n_unsigned % 10 == 9 || n_unsigned >= 90)
    {
        //@ assert n_unsigned % 10 == 9 || n_unsigned >= 90;
        result = true;
    }
    else
    {
        //@ assert n_unsigned % 10 != 9 && n_unsigned < 90;
        result = false;
    }

    return result;
}
