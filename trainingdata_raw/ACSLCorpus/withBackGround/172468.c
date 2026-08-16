#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sum(integer x, integer y) = x + y;

    lemma min_ab_def:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            (sum(a,b) < sum(c,d) ==> sum(a,b) == (sum(a,b) < sum(c,d) ? sum(a,b) : sum(c,d))) &&
            (sum(a,b) >= sum(c,d) ==> sum(c,d) == (sum(a,b) < sum(c,d) ? sum(a,b) : sum(c,d)));

    lemma min_cd_def:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            (sum(c,d) < sum(a,b) ==> sum(c,d) == (sum(c,d) < sum(a,b) ? sum(c,d) : sum(a,b))) &&
            (sum(c,d) >= sum(a,b) ==> sum(a,b) == (sum(c,d) < sum(a,b) ? sum(c,d) : sum(a,b)));
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == ( (a + b) <= (c + d) || (c + d) <= (a + b) );
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int sum_ab;
    int sum_cd;

    sum_ab = a + b;
    sum_cd = c + d;

    //@ assert sum_ab == sum(a,b);
    //@ assert sum_cd == sum(c,d);

    if (sum_ab < sum_cd)
    {
        min_ab = sum_ab;
    }
    else
    {
        min_ab = sum_cd;
    }

    //@ assert min_ab == sum_ab || min_ab == sum_cd;

    if (sum_cd < sum_ab)
    {
        min_cd = sum_cd;
    }
    else
    {
        min_cd = sum_ab;
    }

    //@ assert min_cd == sum_cd || min_cd == sum_ab;
    //@ assert min_ab <= min_cd || min_cd <= min_ab;

    return (min_ab <= min_cd) || (min_cd <= min_ab);
}
