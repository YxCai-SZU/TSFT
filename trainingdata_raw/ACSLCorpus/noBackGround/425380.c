#include <stdint.h>

/*@
    requires (1 <= (m) && (m) <= 23);
    ensures \result == (48 - (m));
    assigns \nothing;
*/
int64_t func(int64_t m)
{
    int64_t ans;
    //@ assert (1 <= (m) && (m) <= 23);
    ans = (24 - m) + 24;
    //@ assert ans == (48 - (m));
    return ans;
}

int main(void)
{
    return 0;
}
