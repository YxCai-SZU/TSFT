#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 3);
    ensures \result == ((k) == 1 ? (a) - (c) :
        (k) == 2 ? (b) :
        (c) - (a));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    int32_t ans = 0;

    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (b) && (b) <= 100 &&         0 <= (c) && (c) <= 100 &&         1 <= (k) && (k) <= 3);
    
    if (k == 1)
    {
        ans = (int32_t)a - (int32_t)c;
        //@ assert ans == ((k) == 1 ? (a) - (c) :         (k) == 2 ? (b) :         (c) - (a));
    }
    else if (k == 2)
    {
        ans = (int32_t)b;
        //@ assert ans == ((k) == 1 ? (a) - (c) :         (k) == 2 ? (b) :         (c) - (a));
    }
    else if (k == 3)
    {
        ans = (int32_t)c - (int32_t)a;
        //@ assert ans == ((k) == 1 ? (a) - (c) :         (k) == 2 ? (b) :         (c) - (a));
    }

    return ans;
}
