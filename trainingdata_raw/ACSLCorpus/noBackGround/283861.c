#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(size_t n, int *a)
{
    int cnt = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= cnt <= i;
        loop invariant ((n) >= 1 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
        loop assigns i, cnt;
        loop variant n - i;
    */
    while (i < n)
    {
        int ai = a[i];
        //@ assert ai >= 1 && ai <= 100;

        if (((i & 1) == 0) && ((ai & 1) == 1))
        {
            cnt += 1;
        }
        i += 1;
    }

    return cnt;
}
