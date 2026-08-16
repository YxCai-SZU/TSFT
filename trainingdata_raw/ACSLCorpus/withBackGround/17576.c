#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = -100 <= x <= 100;
    predicate condition1(integer a, integer b, integer c) = a == b && a != c;
    predicate condition2(integer a, integer b, integer c) = a != b && b == c;
    predicate condition3(integer a, integer b, integer c) = a == c && a != b;
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures condition1(a, b, c) ==> \result == c;
    ensures condition2(a, b, c) ==> \result == a;
    ensures condition3(a, b, c) ==> \result == b;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;

    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);

    if (a == b)
    {
        ans = c;
    }
    else if (a == c)
    {
        ans = b;
    }
    else
    {
        ans = a;
    }

    return ans;
}
