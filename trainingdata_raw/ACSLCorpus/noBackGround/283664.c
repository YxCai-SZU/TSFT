#include <limits.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((((l) / 3)) * (((l) / 3)) * (((l) / 3)));
    ensures 0 <= \result <= 333 * 333 * 333;
*/
int func(int l)
{
    int w = 0;
    int temp_l = l;
    const int divisor = 3;

    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant 0 <= w <= ((l) / 3);
        loop invariant temp_l == l - w * divisor;
        loop invariant 0 <= temp_l;
        loop assigns w, temp_l;
        loop variant temp_l;
    */
    while (temp_l >= divisor)
    {
        temp_l -= divisor;
        w += 1;
    }

    //@ assert 0 <= w && w <= 333;

    //@ assert w >= 0 && w <= 333;

    //@ assert (w * w) >= 0 && (w * w) <= 333 * 333;

    //@ assert (w * w * w) >= 0 && (w * w * w) <= 333 * 333 * 333;

    //@ assert (w * w * w) <= 333 * 333 * 333;

    int ans = w * w * w;
    return ans;
}
