#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t min_ab;
    int64_t min_bc;
    int64_t min_ca;
    int64_t x;
    int64_t ans;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    //@ assert 2 <= b + c <= 200;

    min_ab = (a < b) ? a : b;
    min_bc = (b < c) ? b : c;
    min_ca = (c < a) ? c : a;
    x = min_ab + min_bc;

    //@ assert 0 <= min_ab <= 100 && 0 <= min_bc <= 100;
    //@ assert 0 <= x <= 200;

    if (c >= x)
    {
        //@ assert 0 <= a + b + c;
        return 0;
    }
    else
    {
        //@ assert x >= c;
        //@ assert 0 <= x - c <= 100;
        ans = x - c;

        //@ assert ans >= 0;
        //@ assert ans <= a + b + c;
        return ans;
    }
}
