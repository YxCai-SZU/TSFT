#include <stdbool.h>

/*@
    predicate is_even(integer a) = a % 2 == 0;
    predicate is_odd(integer a) = a % 2 != 0;
*/

/*@
    requires 1 <= a <= 100;
    ensures is_even(a) ==> \result == 1;
    ensures is_odd(a) ==> \result == 0;
*/
int func(int a)
{
    int ans;
    //@ ghost int original_a = a;

    if (a % 2 == 0)
    {
        ans = 1;
        //@ assert ans == 1;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }

    return ans;
}
