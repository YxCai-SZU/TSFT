#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    ensures \result == a * d || \result == a * c || \result == b * d || \result == b * c;
    ensures (-1000000000000000000 <= (\result) <= 1000000000000000000);
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max_ac;
    long long max_bd;
    long long res;

    //@ assert (-1000000000000000000 <= (a * c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a * d) <= 1000000000000000000);
    max_ac = (a * c > a * d) ? a * c : a * d;

    //@ assert (-1000000000000000000 <= (b * c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b * d) <= 1000000000000000000);
    max_bd = (b * c > b * d) ? b * c : b * d;

    //@ assert (-1000000000000000000 <= (max_ac) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (max_bd) <= 1000000000000000000);
    res = (max_ac > max_bd) ? max_ac : max_bd;

    return res;
}
