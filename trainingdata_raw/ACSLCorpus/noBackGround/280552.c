#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (x) <= 200);
    ensures ((\result) == ((x) >= (a) && (x) <= (a) + (b)));
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    unsigned long long start;
    unsigned long long end;
    unsigned long long state;

    start = 0;
    end = a + b;
    state = start;

    //@ assert start == 0;
    //@ assert end == a + b;
    //@ assert state >= start;
    //@ assert state <= x;

    if (x < a || x > end)
    {
        return false;
    }
    else
    {
        /*@
            loop invariant start == 0;
            loop invariant end == a + b;
            loop invariant state >= start;
            loop invariant state <= x;
            loop invariant (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (x) <= 200);
            loop assigns state;
            loop variant x - state;
        */
        while (state < x)
        {
            //@ assert state < x;
            state = state + 1;
            //@ assert state <= x;
        }
        //@ assert state == x;
        return true;
    }
}
