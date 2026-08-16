#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (a == c && b == d) || (a == d && b == c);
    assigns \nothing;
 */
bool func(int a, int b, int c, int d)
{
    bool is_same = false;

    if (a == c)
    {
        is_same = (b == d);
    }
    else if (a == d)
    {
        is_same = (b == c);
    }

    //@ assert is_same == true <==> (a == c && b == d) || (a == d && b == c);

    return is_same;
}
