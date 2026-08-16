#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == (a + d >= c && a + b + c + d >= c);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d)
{
    long max_val;
    long min_val;
    bool result;

    max_val = (c > a + b) ? c : (a + b);
    min_val = (a + b < c) ? (a + b) : c;

    //@ assert max_val == c || max_val == a + b;
    //@ assert min_val == a + b || min_val == c;

    result = (a + d >= c) && (a + b + c + d >= c);
    return result;
}
