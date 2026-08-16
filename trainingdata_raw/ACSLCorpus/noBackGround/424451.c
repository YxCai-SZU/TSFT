#include <limits.h>

/*@
    requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 5000;
    requires 1 <= d <= 5000;
    ensures \result >=
        (a < b ? a : b) + (c < d ? c : d);
    ensures \result <=
        (a > b ? a : b) + (c > d ? c : d);
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int max_ab;
    int max_cd;
    int diff;
    int result;

    //@ assert 1 <= a <= 5000 && 1 <= b <= 5000 && 1 <= c <= 5000 && 1 <= d <= 5000;

    min_ab = (a < b) ? a : b;
    //@ assert (((a) <= (b) ==> (min_ab) == (a)) && ((a) > (b) ==> (min_ab) == (b)));

    min_cd = (c < d) ? c : d;
    //@ assert (((c) <= (d) ==> (min_cd) == (c)) && ((c) > (d) ==> (min_cd) == (d)));

    max_ab = (a > b) ? a : b;
    //@ assert (((a) >= (b) ==> (max_ab) == (a)) && ((a) < (b) ==> (max_ab) == (b)));

    max_cd = (c > d) ? c : d;
    //@ assert (((c) >= (d) ==> (max_cd) == (c)) && ((c) < (d) ==> (max_cd) == (d)));

    //@ assert min_ab + max_ab == a + b;
    //@ assert min_cd + max_cd == c + d;

    diff = max_ab + max_cd - (min_ab + min_cd);
    //@ assert diff == (max_ab - min_ab) + (max_cd - min_cd);

    result = min_ab + min_cd + ((diff > 0) ? diff : 0);
    //@ assert result >= min_ab + min_cd;
    //@ assert result <= max_ab + max_cd;

    return result;
}
