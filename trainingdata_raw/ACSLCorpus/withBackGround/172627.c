#include <limits.h>

/*@
    predicate is_valid_input(integer a, integer b, integer c, integer d) =
        1 <= a && a <= 10000 &&
        1 <= b && b <= 10000 &&
        1 <= c && c <= 10000 &&
        1 <= d && d <= 10000;

    logic integer sum_all(integer a, integer b, integer c, integer d) = a + b + c + d;
    logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_ac(integer a, integer c) = a + c;
    logic integer sum_ad(integer a, integer d) = a + d;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_bd(integer b, integer d) = b + d;
    logic integer sum_cd(integer c, integer d) = c + d;

    predicate is_possible_result(integer a, integer b, integer c, integer d, integer r) =
        r == sum_all(a, b, c, d) ||
        r == sum_ab(a, b) ||
        r == sum_ac(a, c) ||
        r == sum_ad(a, d) ||
        r == sum_bc(b, c) ||
        r == sum_bd(b, d) ||
        r == sum_cd(c, d) ||
        r == a ||
        r == b ||
        r == c ||
        r == d;

    lemma max_is_possible:
        \forall integer a, b, c, d, max_val;
        is_valid_input(a, b, c, d) &&
        (max_val == sum_all(a, b, c, d) ||
         max_val == sum_ab(a, b) ||
         max_val == sum_ac(a, c) ||
         max_val == sum_ad(a, d) ||
         max_val == sum_bc(b, c) ||
         max_val == sum_bd(b, d) ||
         max_val == sum_cd(c, d) ||
         max_val == a ||
         max_val == b ||
         max_val == c ||
         max_val == d) ==>
        is_possible_result(a, b, c, d, max_val);
*/

/*@
    requires is_valid_input(a, b, c, d);
    ensures is_possible_result(a, b, c, d, \result);
*/
int func(int a, int b, int c, int d)
{
    int s1, s2, s3, s4, s5, s6;
    int max_val;

    s1 = a + b;
    s2 = a + c;
    s3 = a + d;
    s4 = b + c;
    s5 = b + d;
    s6 = c + d;

    max_val = s1;
    //@ assert max_val == sum_ab(a, b);
    if (s2 > max_val)
    {
        max_val = s2;
        //@ assert max_val == sum_ac(a, c);
    }
    if (s3 > max_val)
    {
        max_val = s3;
        //@ assert max_val == sum_ad(a, d);
    }
    if (s4 > max_val)
    {
        max_val = s4;
        //@ assert max_val == sum_bc(b, c);
    }
    if (s5 > max_val)
    {
        max_val = s5;
        //@ assert max_val == sum_bd(b, d);
    }
    if (s6 > max_val)
    {
        max_val = s6;
        //@ assert max_val == sum_cd(c, d);
    }
    if (a > max_val)
    {
        max_val = a;
        //@ assert max_val == a;
    }
    if (b > max_val)
    {
        max_val = b;
        //@ assert max_val == b;
    }
    if (c > max_val)
    {
        max_val = c;
        //@ assert max_val == c;
    }
    if (d > max_val)
    {
        max_val = d;
        //@ assert max_val == d;
    }

    //@ assert is_possible_result(a, b, c, d, max_val);
    return max_val;
}
