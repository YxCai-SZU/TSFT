#include <limits.h>

/*@
    requires (0 <= (A) <= 100 && 0 <= (B) <= 100 && 0 <= (C) <= 100);
    ensures 0 <= \result <= A + B + C;
    ensures \result >= 0;
    assigns \nothing;
*/
long long count_max_tasty_cookies(long long A, long long B, long long C)
{
    long long min_val;
    long long ans;

    //@ assert A + B <= 200;
    //@ assert A + C <= 200;
    //@ assert B + C <= 200;
    //@ assert A + B + C <= 300;

    if (C < A + B + 1)
    {
        min_val = C;
    }
    else
    {
        min_val = A + B + 1;
    }

    ans = B + min_val;

    //@ assert ans >= 0;
    //@ assert ans <= A + B + C;

    return ans;
}
