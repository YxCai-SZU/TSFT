#include <stdbool.h>

/*@
    requires (\valid((xs) + (0..2)) &&
        1 <= (xs)[0] && (xs)[0] <= 100 &&
        1 <= (xs)[1] && (xs)[1] <= 100 &&
        1 <= (xs)[2] && (xs)[2] <= 100);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (xs[0] == xs[1] && xs[0] == xs[2]);
    ensures \result == 2 ==> (xs[0] == xs[1] || xs[0] == xs[2] || xs[1] == xs[2]);
    ensures \result == 3 ==> (xs[0] != xs[1] && xs[0] != xs[2] && xs[1] != xs[2]);
    assigns \nothing;
*/
int func(int *xs)
{
    int cnt = 0;
    int ans;

    //@ assert (\valid((xs) + (0..2)) &&         1 <= (xs)[0] && (xs)[0] <= 100 &&         1 <= (xs)[1] && (xs)[1] <= 100 &&         1 <= (xs)[2] && (xs)[2] <= 100);

    if (xs[0] == xs[1])
    {
        cnt += 1;
    }
    //@ assert cnt == (xs[0] == xs[1] ? 1 : 0);

    if (xs[0] == xs[2])
    {
        cnt += 1;
    }
    //@ assert cnt == (xs[0] == xs[1] ? 1 : 0) + (xs[0] == xs[2] ? 1 : 0);

    if (xs[1] == xs[2])
    {
        cnt += 1;
    }
    //@ assert cnt == (((xs[0]) == (xs[1]) ? 1 : 0) +         ((xs[0]) == (xs[2]) ? 1 : 0) +         ((xs[1]) == (xs[2]) ? 1 : 0));

    if (cnt == 0)
    {
        ans = 3;
    }
    else if (cnt == 1 || cnt == 2)
    {
        ans = 2;
    }
    else
    {
        ans = 1;
    }

    //@ assert ans >= 1 && ans <= 3;
    //@ assert ans == 1 || ans == 2 || ans == 3;
    //@ assert ans == 1 ==> (xs[0] == xs[1] && xs[0] == xs[2]);
    //@ assert ans == 2 ==> (xs[0] == xs[1] || xs[0] == xs[2] || xs[1] == xs[2]);
    //@ assert ans == 3 ==> (xs[0] != xs[1] && xs[0] != xs[2] && xs[1] != xs[2]);

    return ans;
}
