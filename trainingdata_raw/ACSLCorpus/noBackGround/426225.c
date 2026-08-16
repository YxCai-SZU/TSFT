#include <limits.h>

/*@
    requires ((l) >= 0 && (b) >= 0 &&
        (l) * (b) <= INT_MAX &&
        (l) * 2 <= INT_MAX &&
        (b) * 2 <= INT_MAX &&
        (l) * 2 + (b) * 2 <= INT_MAX);
    ensures \result == ((l) * (b));
    assigns \nothing;
*/
int rectangle_area(int l, int b)
{
    //@ assert l >= 0 && b >= 0;
    //@ assert l * b <= INT_MAX;
    return l * b;
}

/*@
    requires ((l) >= 0 && (b) >= 0 &&
        (l) * (b) <= INT_MAX &&
        (l) * 2 <= INT_MAX &&
        (b) * 2 <= INT_MAX &&
        (l) * 2 + (b) * 2 <= INT_MAX);
    ensures \result == (2 * ((l) + (b)));
    assigns \nothing;
*/
int rectangle_perimeter(int l, int b)
{
    //@ assert l * 2 <= INT_MAX && b * 2 <= INT_MAX;
    //@ assert l * 2 + b * 2 <= INT_MAX;
    return 2 * (l + b);
}
