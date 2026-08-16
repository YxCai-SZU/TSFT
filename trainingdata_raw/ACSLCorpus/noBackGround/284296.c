#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int x;
    int y;
    int max_value;

    //@ assert (-10000 <= (a * c) <= 10000);
    //@ assert (-10000 <= (a * d) <= 10000);
    //@ assert (-10000 <= (b * c) <= 10000);
    //@ assert (-10000 <= (b * d) <= 10000);

    if (a * c > a * d)
        x = a * c;
    else
        x = a * d;

    if (b * c > b * d)
        y = b * c;
    else
        y = b * d;

    if (x > y)
        max_value = x;
    else
        max_value = y;

    return max_value;
}
