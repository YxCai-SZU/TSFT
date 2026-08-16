#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100);
    ensures ((\result) >= 0 &&
        (\result) <= (A) &&
        ((\result) == (A) - 2 * (B) || (\result) == 0));
*/
int func(int A, int B)
{
    int ans;
    int res;

    //@ assert 2 * B <= 200;
    //@ assert A - 2 * B <= 100;

    ans = A - 2 * B;

    if (ans > 0)
    {
        //@ assert ans >= 0;
        //@ assert ans <= A;
        //@ assert ans == A - 2 * B;
        res = ans;
    }
    else
    {
        res = 0;
    }

    return res;
}
