#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures (((((a)) + ((b))) < 20 ==> (\result) == 0) &&
        ((((a)) + ((b))) >= 20 ==> (\result) == 1));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t sub;
    int32_t ans;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;

    sub = a + b;

    //@ assert sub == ((a) + (b));

    if (sub < 20)
    {
        ans = 0;
    }
    else
    {
        ans = 1;
    }

    //@ assert (sub < 20 ==> ans == 0) && (sub >= 20 ==> ans == 1);

    return ans;
}
