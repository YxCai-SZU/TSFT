#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((l) / 3)*((l) / 3)*((l) / 3);
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    int64_t w = 0;
    int64_t temp_l = l;

    /*@
        loop invariant 0 <= w <= ((l) / 3);
        loop invariant temp_l == l - 3*w;
        loop invariant 1 <= l <= 1000;
        loop assigns w, temp_l;
        loop variant temp_l;
    */
    while (temp_l >= 3)
    {
        temp_l -= 3;
        w += 1;
    }

    //@ assert 0 <= w && w <= 333;
    //@ assert w == ((l) / 3);
    //@ assert 0 <= w*w && w*w <= 333*333;
    //@ assert 0 <= w*w*w && w*w*w <= 333*333*333;
    //@ assert w*w*w == ((l) / 3)*((l) / 3)*((l) / 3);

    return w * w * w;
}
