#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 9 &&
        1 <= (b) && (b) <= 9 &&
        1 <= (c) && (c) <= 9);
    ensures ((\result) == (((a)) * 10 + ((b)) + ((c))) ||
        (\result) == (((a)) + ((b)) * 10 + ((c))) ||
        (\result) == (((a)) + ((b)) + ((c)) * 10));
    ensures \result >= 0;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t ans1;
    int64_t ans2;
    int64_t ans3;
    int64_t ans;

    ans1 = a * 10 + b + c;
    ans2 = a + b * 10 + c;
    ans3 = a + b + c * 10;

    ans = ans1;
    //@ assert ans == ans1 || ans == ans2 || ans == ans3;

    if (ans2 > ans)
    {
        ans = ans2;
        //@ assert ans == ans1 || ans == ans2 || ans == ans3;
    }

    if (ans3 > ans)
    {
        ans = ans3;
        //@ assert ans == ans1 || ans == ans2 || ans == ans3;
    }

    //@ assert ((ans) == (((a)) * 10 + ((b)) + ((c))) ||         (ans) == (((a)) + ((b)) * 10 + ((c))) ||         (ans) == (((a)) + ((b)) + ((c)) * 10));
    //@ assert ans >= 0;
    return ans;
}
