#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000) && 
              (-1000 <= (c) <= 1000) && (-1000 <= (d) <= 1000);
    ensures \result == ((a) * (b)) || \result == ((a) * (c)) || 
            \result == ((a) * (d)) || \result == ((b) * (c)) || 
            \result == ((b) * (d)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((a) * (c));
    ensures \result >= ((a) * (d));
    ensures \result >= ((b) * (c));
    ensures \result >= ((b) * (d));
    ensures \result >= ((c) * (d));
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int max_ab_c;
    int max_cd_d;
    int max_all;

    //@ assert -1000000 <= a * b <= 1000000;
    //@ assert -1000000 <= b * c <= 1000000;
    //@ assert -1000000 <= c * d <= 1000000;
    //@ assert -1000000 <= d * a <= 1000000;
    //@ assert -1000000 <= a * c <= 1000000;
    //@ assert -1000000 <= b * d <= 1000000;

    if (a * b > b * c)
        max_ab = a * b;
    else
        max_ab = b * c;

    if (c * d > d * a)
        max_cd = c * d;
    else
        max_cd = d * a;

    if (max_ab > a * c)
        max_ab_c = max_ab;
    else
        max_ab_c = a * c;

    if (max_cd > b * d)
        max_cd_d = max_cd;
    else
        max_cd_d = b * d;

    if (max_ab_c > max_cd_d)
        max_all = max_ab_c;
    else
        max_all = max_cd_d;

    return max_all;
}
