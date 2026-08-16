#include <stdbool.h>

/*@
    predicate is_strictly_increasing(integer a, integer b, integer c) =
        a < b && b < c;
    predicate is_strictly_decreasing(integer a, integer b, integer c) =
        a > b && b > c;
*/

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result == ( (a < b && b < c) || (a > b && b > c) );
*/
bool func(int a, int b, int c)
{
    bool ans;
    //@ ghost bool ans_spec;

    ans = (a < b && b < c);
    //@ ghost ans_spec = ans;

    if (a > b && b > c) {
        ans = true;
        //@ ghost ans_spec = true;
    }

    //@ assert ans_spec == ( (a < b && b < c) || (a > b && b > c) );
    //@ assert ans == ans_spec;

    return ans;
}
