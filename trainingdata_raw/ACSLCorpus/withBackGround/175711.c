/*@
    predicate is_possible(integer a, integer b, integer x) =
        x >= a && x <= a + b;

    lemma loop_invariant_holds:
        \forall integer a, integer b, integer x, integer i;
        a <= i <= a + b + 1 &&
        0 <= a <= 1000000000 &&
        0 <= b <= 1000000000 &&
        0 <= x <= 1000000000 &&
        (x < a || x >= i) ==>
        \true;
*/

#include <stdbool.h>

/*@
    requires 0 <= a <= 1000000000;
    requires 0 <= b <= 1000000000;
    requires 0 <= x <= 1000000000;
    ensures \result == true <==> (x >= a && x <= a + b);
*/
bool is_possible_to_have_x_cats(long long a, long long b, long long x)
{
    long long i;
    i = a;

    /*@
        loop invariant a <= i <= a + b + 1;
        loop invariant 0 <= a <= 1000000000;
        loop invariant 0 <= b <= 1000000000;
        loop invariant 0 <= x <= 1000000000;
        loop invariant x < a || x >= i;
        loop assigns i;
        loop variant a + b + 1 - i;
    */
    while (i <= a + b)
    {
        //@ assert x < a || x >= i;
        if (i == x)
        {
            //@ assert x >= a && x <= a + b;
            return true;
        }
        i = i + 1;
    }
    //@ assert x < a || x > a + b;
    return false;
}
