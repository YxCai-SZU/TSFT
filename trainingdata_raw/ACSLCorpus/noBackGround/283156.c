#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000) && (-1000 <= (c) <= 1000) && (-1000 <= (d) <= 1000);
    ensures \result == a*d || \result == b*c || \result == a*c || \result == b*d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_val1;
    int max_val2;
    int result;

    //@ assert -1000000 <= a*c <= 1000000;
    //@ assert -1000000 <= a*d <= 1000000;
    if (a * c > a * d) {
        max_val1 = a * c;
    } else {
        max_val1 = a * d;
    }

    //@ assert -1000000 <= b*c <= 1000000;
    //@ assert -1000000 <= b*d <= 1000000;
    if (b * c > b * d) {
        max_val2 = b * c;
    } else {
        max_val2 = b * d;
    }

    //@ assert max_val1 == a*c || max_val1 == a*d;
    //@ assert max_val2 == b*c || max_val2 == b*d;
    if (max_val1 > max_val2) {
        result = max_val1;
    } else {
        result = max_val2;
    }

    return result;
}
