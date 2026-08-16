#include <limits.h>

/*@
    predicate is_valid_input(integer a, integer b, integer c, integer d) =
        -100 <= a && a <= 100 &&
        -100 <= b && b <= 100 &&
        -100 <= c && c <= 100 &&
        -100 <= d && d <= 100;

    logic integer max(integer x, integer y) = (x >= y) ? x : y;

    logic integer sum(integer x, integer y) = x + y;

    predicate is_possible_result(integer res, integer a, integer b, integer c, integer d) =
        res == a || res == b || res == c || res == d ||
        res == a + b || res == a + c || res == a + d ||
        res == b + c || res == b + d || res == c + d ||
        res == a + b + c || res == a + b + d || res == a + c + d || res == b + c + d ||
        res == a + b + c + d;

    lemma possible_result_lemma:
        \forall integer a, b, c, d, max1, max2, sum1, sum2, res;
        is_valid_input(a, b, c, d) &&
        max1 == max(a, b) &&
        max2 == max(c, d) &&
        sum1 == max(a + b, a + c) &&
        sum2 == max(b + d, c + d) &&
        res == max(max1 + max2, max(sum1, sum2)) ==>
        is_possible_result(res, a, b, c, d);
*/

/*@
    requires is_valid_input(a, b, c, d);
    ensures is_possible_result(\result, a, b, c, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int sum1;
    int sum2;
    int res;

    max1 = a;
    max2 = c;
    sum1 = a + b;
    sum2 = c + d;

    //@ assert max1 == a && max2 == c && sum1 == a + b && sum2 == c + d;

    if (max1 < b)
    {
        max1 = b;
    }
    //@ assert max1 == max(a, b);

    if (max2 < d)
    {
        max2 = d;
    }
    //@ assert max2 == max(c, d);

    if (sum1 < a + c)
    {
        sum1 = a + c;
    }
    //@ assert sum1 == max(a + b, a + c);

    if (sum2 < b + d)
    {
        sum2 = b + d;
    }
    //@ assert sum2 == max(b + d, c + d);

    res = max1 + max2;
    //@ assert res == max(a, b) + max(c, d);

    if (res < sum1)
    {
        res = sum1;
    }
    //@ assert res == max(max(a, b) + max(c, d), max(a + b, a + c));

    if (res < sum2)
    {
        res = sum2;
    }
    //@ assert res == max(max(max(a, b) + max(c, d), max(a + b, a + c)), max(b + d, c + d));

    //@ assert is_possible_result(res, a, b, c, d);
    return res;
}
