#include <stdint.h>

/*@
    requires \valid(v+(0..3));
    requires ((4) == 4 &&
        (v)[0] >= 0 && (v)[0] < 24 &&
        (v)[1] >= 0 && (v)[1] < 60 &&
        (v)[2] >= 0 && (v)[2] < 24 &&
        (v)[3] >= 0 && (v)[3] < 60);
    ensures \result >= 0;
    ensures \result <= 60 * 24;
    assigns \nothing;
*/
int32_t func(int32_t *v)
{
    int32_t t1;
    int32_t t2;
    int32_t result;

    t1 = v[0] * 60 + v[1];
    t2 = v[2] * 60 + v[3];

    //@ assert 0 <= t1 <= 24*60;
    //@ assert 0 <= t2 <= 24*60;

    if (t1 < t2)
    {
        result = t2 - t1;
    }
    else
    {
        result = 24 * 60 - t1 + t2;
    }

    //@ assert result == ((t1) < (t2) ? (t2) - (t1) : 24 * 60 - (t1) + (t2));

    return result;
}
