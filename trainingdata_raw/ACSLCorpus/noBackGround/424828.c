#include <stdbool.h>

/*@
    requires 1 <= N <= 100;
    ensures \result == (N + 1) / 2;
*/
int func(int N)
{
    int ans;
    int count;
    ans = N + 1;
    count = 0;

    /*@
        loop invariant (0 <= (ans) <= (N) + 1);
        loop invariant (0 <= (count) <= ((N) + 1) / 2);
        loop invariant ((ans) == (N) + 1 - 2 * (count));
        loop invariant ((count) == ((N) + 1 - (ans)) / 2);
        loop assigns ans, count;
        loop variant ans;
    */
    while (ans > 1)
    {
        //@ assert ans > 1;
        ans = ans - 2;
        count = count + 1;
    }
    //@ assert ans <= 1;
    return count;
}
