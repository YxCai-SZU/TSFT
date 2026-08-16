#include <stdbool.h>
/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    //@ assert 1 <= ((a) * (b)) <= 10000;
    if (c < a * b)
    {
        ans = c;
    }
    else
    {
        ans = a * b;
    }
    //@ assert ans >= 0;
    //@ assert ans <= ((a) * (b));
    return ans;
}
