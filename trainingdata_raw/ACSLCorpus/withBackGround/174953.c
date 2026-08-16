#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer calculate_result(integer a, integer b, integer c) =
        a == b && b == c ? 3 :
        a == b || b == c || a == c ? 2 :
        1;

    lemma result_in_range:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            1 <= calculate_result(a, b, c) <= 10;

    lemma result_discrete:
        \forall integer a, b, c, r;
            valid_range(a) && valid_range(b) && valid_range(c) &&
            r == calculate_result(a, b, c) ==>
            (r == 1 || r == 2 || r == 3 || r == 4 || r == 5 ||
             r == 6 || r == 7 || r == 8 || r == 9 || r == 10);
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result >= 1 && \result <= 10;
    ensures \result == 1 || \result == 2 || \result == 3 || \result == 4 || 
            \result == 5 || \result == 6 || \result == 7 || \result == 8 || 
            \result == 9 || \result == 10;
*/
int func(int a, int b, int c)
{
    int ans;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);

    if (a == b && b == c) {
        ans = 3;
    } else if (a == b || b == c || a == c) {
        ans = 2;
    } else {
        ans = 1;
    }

    //@ assert ans == calculate_result(a, b, c);
    //@ assert ans >= 1 && ans <= 10;
    //@ assert ans == 1 || ans == 2 || ans == 3 || ans == 4 || ans == 5 || ans == 6 || ans == 7 || ans == 8 || ans == 9 || ans == 10;

    return ans;
}
