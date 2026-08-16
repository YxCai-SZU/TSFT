#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000) && (-1000 <= (c) <= 1000) && (-1000 <= (d) <= 1000);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d || \result == c * b;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int res;
    int max_val;
    int temp_val;

    //@ assert (-1000000 <= (a) * (c) <= 1000000);
    res = a * c;

    //@ assert (-1000000 <= (a) * (d) <= 1000000);
    max_val = res;
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    res = max_val;

    //@ assert (-1000000 <= (b) * (d) <= 1000000);
    max_val = res;
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    res = max_val;

    //@ assert (-1000000 <= (c) * (b) <= 1000000);
    max_val = res;
    temp_val = c * b;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    res = max_val;

    return res;
}
