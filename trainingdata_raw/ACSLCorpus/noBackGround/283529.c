#include <limits.h>

/*@
    requires ((n) >= 1 && (n) <= 100 &&
        (k) >= 1 && (k) <= 100);
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
    ensures \result >= 0;
*/
int func(int n, int k, int *a)
{
    int min = INT_MAX;
    int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant min >= 0;
        loop invariant ((n) >= 1 && (n) <= 100 &&
        (k) >= 1 && (k) <= 100);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
        loop assigns i, min;
        loop variant n - i;
    */
    while (i < n)
    {
        int l = a[i];
        int current = 0;
        int j = 0;

        //@ assert l >= 1 && l <= 100;

        /*@
            loop invariant 0 <= j <= k;
            loop invariant current >= 0;
            loop invariant current <= j * 200;
            loop invariant ((n) >= 1 && (n) <= 100 &&
        (k) >= 1 && (k) <= 100);
            loop invariant (\forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
            loop assigns j, current;
            loop variant k - j;
        */
        while (j < k)
        {
            if ((j & 1) == 0 && j != 0)
            {
                current += 2 * l;
            }
            j++;
        }

        if (current < min)
        {
            min = current;
        }
        i++;
    }

    //@ assert min >= 0;
    return min;
}
