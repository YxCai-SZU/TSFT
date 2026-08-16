#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == (a * b > c * d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    bool result;
    long long product_ab, product_cd;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    //@ assert a <= 10000 && b <= 10000;
    //@ assert c <= 10000 && d <= 10000;

    //@ assert 1 <= a * b <= 10000 * 10000;
    //@ assert 1 <= c * d <= 10000 * 10000;

    product_ab = (long long)a * b;
    product_cd = (long long)c * d;
    result = product_ab > product_cd;

    //@ assert result == (a * b > c * d);
    return result;
}
