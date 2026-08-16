#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    logic integer division_modulus(integer b, integer r) = b - 2 * r;

    lemma division_property:
        \forall integer b, r;
            0 <= r <= b/2 && division_modulus(b, r) >= 0 ==>
            division_modulus(b, r) <= b;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == a + b + c ||
            \result == a + b + c + 1 ||
            \result == a + b + c + 2;
*/
int func(int a, int b, int c)
{
    int ans;
    int r;
    int temp_b;

    ans = a + b + c;
    r = 0;
    temp_b = b;

    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant 0 <= r <= b / 2;
        loop invariant temp_b == b - 2 * r;
        loop assigns temp_b, r;
    */
    while (temp_b >= 2)
    {
        //@ assert temp_b >= 2;
        temp_b -= 2;
        r += 1;
    }

    //@ assert temp_b == b - 2 * r;
    //@ assert 0 <= temp_b <= 1;

    if (r >= 3)
    {
        ans += 1;
    }

    return ans;
}
