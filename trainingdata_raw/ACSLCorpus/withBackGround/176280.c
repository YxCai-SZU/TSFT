#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sum1(integer a, integer b) = a + b;
    logic integer sum2(integer b, integer c) = b + c;
    logic integer sum3(integer c, integer a) = c + a;

    predicate check_condition(integer a, integer b, integer c) =
        sum1(a, b) == c || sum2(b, c) == a || sum3(c, a) == b;

    lemma sum_bounds1: \forall integer a, b; valid_range(a) && valid_range(b) ==> 1 <= sum1(a, b) <= 200;
    lemma sum_bounds2: \forall integer b, c; valid_range(b) && valid_range(c) ==> 1 <= sum2(b, c) <= 200;
    lemma sum_bounds3: \forall integer c, a; valid_range(c) && valid_range(a) ==> 1 <= sum3(c, a) <= 200;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == true <==> check_condition(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool ret;
    int sum1_val;
    int sum2_val;
    int sum3_val;

    ret = false;
    sum1_val = a + b;
    sum2_val = b + c;
    sum3_val = c + a;

    //@ assert 1 <= sum1_val <= 200;
    //@ assert 1 <= sum2_val <= 200;
    //@ assert 1 <= sum3_val <= 200;

    if (sum1_val == c)
    {
        ret = true;
    }
    if (sum2_val == a)
    {
        ret = true;
    }
    if (sum3_val == b)
    {
        ret = true;
    }

    //@ assert sum1_val <= 200;
    return ret;
}
