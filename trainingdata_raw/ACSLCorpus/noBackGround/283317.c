#include <stdint.h>

/*@
    requires ((x) <= 1);
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t ans;
    //@ assert x <= 1;
    ans = 1 - (int32_t)x;
    //@ assert ans == 1 || ans == 0;
    return ans;
}

int main()
{
    return 0;
}
