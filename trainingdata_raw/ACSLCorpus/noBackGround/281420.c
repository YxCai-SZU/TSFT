#include <stdint.h>

/*@
    requires (-40 <= (x) && (x) <= 40);
    ensures (((\result) == 0 || (\result) == 1) &&
        ((\result) == 1 ==> (x) >= 30) &&
        ((\result) == 0 ==> (x) < 30));
*/
int64_t func(int64_t x)
{
    int64_t ans;
    //@ assert (-40 <= (x) && (x) <= 40);
    if (x < 30)
    {
        ans = 0;
        //@ assert ans == 0;
    }
    else
    {
        ans = 1;
        //@ assert ans == 1;
    }
    //@ assert (((ans) == 0 || (ans) == 1) &&         ((ans) == 1 ==> (x) >= 30) &&         ((ans) == 0 ==> (x) < 30));
    return ans;
}
