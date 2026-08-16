#include <stdint.h>

/*@
    requires (2 <= (a) <= 100 && 2 <= (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t ans;
    //@ assert 1 <= a - 1 <= 99;
    //@ assert 1 <= b - 1 <= 99;
    //@ assert 1 <= (a - 1) * (b - 1) <= 9801;
    ans = (a - 1) * (b - 1);
    return ans;
}
