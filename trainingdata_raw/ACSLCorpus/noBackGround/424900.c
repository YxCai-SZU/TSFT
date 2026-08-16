#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==>
            (a >= c && a - c >= d) ||
            (b >= c && b - c >= d) ||
            (a >= c && b >= d && a - c <= d && b - d <= d && (a - c) + (b - d) >= d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    bool result = false;

    //@ assert ((a) >= (c) && (a) - (c) >= (d)) || !((a) >= (c) && (a) - (c) >= (d));
    if (a >= c && a - c >= d)
    {
        result = true;
    }

    //@ assert ((b) >= (c) && (b) - (c) >= (d)) || !((b) >= (c) && (b) - (c) >= (d));
    if (b >= c && b - c >= d)
    {
        result = true;
    }

    //@ assert ((a) >= (c) && (b) >= (d) &&         (a) - (c) <= (d) && (b) - (d) <= (d) &&         ((a) - (c)) + ((b) - (d)) >= (d)) || !((a) >= (c) && (b) >= (d) &&         (a) - (c) <= (d) && (b) - (d) <= (d) &&         ((a) - (c)) + ((b) - (d)) >= (d));
    if (a >= c && b >= d && a - c <= d && b - d <= d && (a - c) + (b - d) >= d)
    {
        result = true;
    }

    //@ assert result == true <==> ((a) >= (c) && (a) - (c) >= (d)) || ((b) >= (c) && (b) - (c) >= (d)) || ((a) >= (c) && (b) >= (d) &&         (a) - (c) <= (d) && (b) - (d) <= (d) &&         ((a) - (c)) + ((b) - (d)) >= (d));
    return result;
}
