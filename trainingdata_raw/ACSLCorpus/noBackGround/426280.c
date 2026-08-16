#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100);
    ensures \result >= 0;
    ensures \result == A - 2 * B || \result == 0;
    assigns \nothing;
*/
int func(int A, int B)
{
    int ans;
    int tmp;

    //@ assert A >= 1 && A <= 100;
    //@ assert B >= 1 && B <= 100;

    tmp = A - 2 * B;
    if (tmp < 0)
    {
        ans = 0;
    }
    else
    {
        ans = tmp;
    }

    //@ assert ans >= 0;
    //@ assert ans == A - 2 * B || ans == 0;

    return ans;
}
