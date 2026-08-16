#include <limits.h>

/*@
    predicate within_range(integer num1, integer num2, integer num3) =
        num1 <= num3 && num3 <= num2;
*/

/*@
    requires num1 < INT_MAX;
    requires num2 < INT_MAX;
    requires num3 < INT_MAX;
    requires num1 < num2;
    ensures \result == 1 <==> (num1 <= num3 && num3 <= num2);
    assigns \nothing;
*/
int is_within_range(int num1, int num2, int num3)
{
    // Variable declarations at top of scope
    int result;

    //@ assert num1 < INT_MAX;
    //@ assert num2 < INT_MAX;
    //@ assert num3 < INT_MAX;
    //@ assert num1 < num2;

    result = (num1 <= num3 && num3 <= num2) ? 1 : 0;
    return result;
}
