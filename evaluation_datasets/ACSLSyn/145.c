#include <limits.h>
#include <stdbool.h>

/*@ predicate valid_range(integer v) = 1 <= v <= 100; */

/*@ logic integer abs(integer x) = x < 0 ? -x : x; */
/*@ logic integer min(integer x, integer y) = x < y ? x : y; */
/*@ logic integer max(integer x, integer y) = x > y ? x : y; */

int func(int a, int b, int c, int d)
{
    int res;
    int res2;
    int res3;

    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 100;
    //@ assert d >= 1 && d <= 100;

    res = a < c ? a : c;
    //@ assert res == min(a, c);

    res2 = b < d ? b : d;
    //@ assert res2 == min(b, d);

    res3 = res + res2;
    //@ assert res3 >= 0;
    //@ assert res3 <= a + b + c + d;

    return res3;
}

int diff(int li1, int li2)
{
    int diff_val;

    //@ assert li1 >= 0 && li2 >= 0;
    //@ assert li1 <= INT_MAX && li2 <= INT_MAX;

    diff_val = li1 > li2 ? li1 - li2 : li2 - li1;
    //@ assert diff_val == li1 - li2 || diff_val == li2 - li1;
    //@ assert diff_val >= 0;
    //@ assert diff_val <= li1 + li2;

    return diff_val;
}

/*@
    predicate is_evenly_distributable(integer a, integer b, integer c) =
        (a + b == c) || (b + c == a) || (c + a == b) || (a + b + c == 3);
 */

bool can_distribute_evenly(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    //@ assert a + b <= 200;
    
    bool result;
    result = (a + b == c || b + c == a || c + a == b) || (a + b + c == 3);
    
    //@ assert result == true <==> is_evenly_distributable(a, b, c);
    return result;
}

/*@
    predicate valid_state(integer a, integer b, integer c, integer d) =
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) &&
        (a + b == c || b + c == a || c + a == b || a + b + c == 3);
    
    predicate valid_output(integer sum_min, integer diff_val, bool distrib) =
        sum_min >= 0 && sum_min <= 400 &&
        diff_val >= 0 && diff_val <= 400 &&
        (diff_val == (sum_min > 100 ? sum_min - 100 : 100 - sum_min) ||
         diff_val == (sum_min > 200 ? sum_min - 200 : 200 - sum_min));
*/

int complex_resource_balancer(int a, int b, int c, int d)
{
    
    int min_sum_1 = func(a, b, c, d);
    int min_sum_2 = func(c, d, a, b);
    int diff_val = diff(min_sum_1, min_sum_2);
    bool distrib_ok = can_distribute_evenly(a, b, c);
    
    //@ assert min_sum_1 >= 0 && min_sum_1 <= a + b + c + d;
    //@ assert min_sum_2 >= 0 && min_sum_2 <= c + d + a + b;
    //@ assert diff_val >= 0 && diff_val <= min_sum_1 + min_sum_2;
    //@ assert distrib_ok == true <==> is_evenly_distributable(a, b, c);
    
    //@ assert diff_val <= 400;
    
    return diff_val;
}
