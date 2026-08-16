#include <stdint.h>

/*@
    requires \valid(v + (0..2));
    requires ((3) == 3 &&
        0 <= (v)[0] && (v)[0] <= 10 &&
        0 <= (v)[1] && (v)[1] <= 10 &&
        0 <= (v)[2] && (v)[2] <= 10);
    assigns \nothing;
    ensures \result == ((v[2]) * 2 + (v[1]) - (v[0])) || \result == 0;
    ensures \result >= 0;
*/
int64_t func(int64_t *v)
{
    int64_t r;
    //@ assert ((3) == 3 &&         0 <= (v)[0] && (v)[0] <= 10 &&         0 <= (v)[1] && (v)[1] <= 10 &&         0 <= (v)[2] && (v)[2] <= 10);
    r = v[2] * 2 + v[1] - v[0];
    if (r > 0)
    {
        //@ assert r == ((v[2]) * 2 + (v[1]) - (v[0]));
        //@ assert r >= 0;
        return r;
    }
    else
    {
        //@ assert r <= 0;
        //@ assert 0 >= 0;
        return 0;
    }
}
