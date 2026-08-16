#include <stdbool.h>

/*@
    predicate is_seven(integer a) = (a / 10 == 7) || (a % 10 == 7);
*/

/*@
    requires 10 <= a <= 99;
    ensures \result == true <==> (a / 10 == 7) || (a % 10 == 7);
    assigns \nothing;
*/
bool func(unsigned long long a)
{
    unsigned long long ten;
    unsigned long long one;
    bool result;

    ten = a / 10;
    one = a % 10;

    if (ten == 7 || one == 7)
    {
        //@ assert ten == 7 || one == 7;
        result = true;
    }
    else
    {
        //@ assert ten != 7 && one != 7;
        result = false;
    }

    return result;
}
