#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == a * d || \result == b * c || \result == a * c;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long max1;
    long max2;
    long max_res;

    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    //@ assert (-1000000000000000000 <= (a * c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a * d) <= 1000000000000000000);
    max1 = (a * c > a * d) ? a * c : a * d;

    //@ assert (-1000000000 <= (b) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    //@ assert (-1000000000000000000 <= (b * c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b * d) <= 1000000000000000000);
    max2 = (b * c > b * d) ? b * c : b * d;

    max_res = (max1 > max2) ? max1 : max2;

    //@ assert max_res == b * d || max_res == a * d || max_res == b * c || max_res == a * c;
    return max_res;
}
