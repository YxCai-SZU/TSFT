#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b;
    requires b != c;
    requires a != c;
    ensures \result == ((a < c && c < b) || (b < c && c < a));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    int min_val;
    int max_val;

    //@ assert a != b && b != c && a != c;

    if (a < b)
    {
        min_val = a;
    }
    else
    {
        min_val = b;
    }

    if (a > b)
    {
        max_val = a;
    }
    else
    {
        max_val = b;
    }

    //@ assert min_val <= max_val;
    //@ assert c <= 100;

    //@ assert (min_val < c && c < max_val) == ((a < c && c < b) || (b < c && c < a));

    return (min_val < c && c < max_val);
}
