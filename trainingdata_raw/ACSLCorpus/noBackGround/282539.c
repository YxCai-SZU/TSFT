#include <stdbool.h>

/*@
    requires 0 <= a <= 10;
    requires 0 <= b <= 10;
    requires 0 <= c <= 10;
    ensures \result == true <==> (a == b + c || b == c + a || c == a + b);
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int max_val;
    unsigned int mid_val;
    unsigned int min_val;
    unsigned int temp;

    max_val = a;
    mid_val = b;
    min_val = c;

    //@ assert max_val == a && mid_val == b && min_val == c;

    if (max_val < mid_val)
    {
        temp = max_val;
        max_val = mid_val;
        mid_val = temp;
    }
    //@ assert max_val >= mid_val;

    if (mid_val < min_val)
    {
        temp = mid_val;
        mid_val = min_val;
        min_val = temp;
    }
    //@ assert mid_val >= min_val;

    if (max_val < mid_val)
    {
        temp = max_val;
        max_val = mid_val;
        mid_val = temp;
    }
    //@ assert max_val >= mid_val && mid_val >= min_val;

    //@ assert max_val == mid_val + min_val <==> (a == b + c || b == c + a || c == a + b);
    return max_val == mid_val + min_val;
}
