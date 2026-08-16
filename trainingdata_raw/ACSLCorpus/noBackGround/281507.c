#include <limits.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((a) + (b) + (c) + (d) - 3 * (((a)) > ((b)) ? ((a)) : ((b))) - 3 * (((c)) > ((d)) ? ((c)) : ((d))));
*/
int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int max_ab;
    unsigned int max_cd;
    int result;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    //@ assert a + b + c + d <= 40000;
    //@ assert 3 * (a > b ? a : b) <= 30000;
    //@ assert 3 * (c > d ? c : d) <= 30000;
    //@ assert (int)(a + b + c + d) - 3 * (int)(a > b ? a : b) - 3 * (int)(c > d ? c : d) >= INT_MIN;

    if (a > b)
        max_ab = a;
    else
        max_ab = b;

    if (c > d)
        max_cd = c;
    else
        max_cd = d;

    result = (int)(a + b + c + d) - 3 * (int)max_ab - 3 * (int)max_cd;

    //@ assert result == ((a) + (b) + (c) + (d) - 3 * (((a)) > ((b)) ? ((a)) : ((b))) - 3 * (((c)) > ((d)) ? ((c)) : ((d))));
    return result;
}
