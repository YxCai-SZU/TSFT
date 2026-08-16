#include <stdbool.h>
#include <stddef.h>

/*@ requires 2 <= n <= 1000000;
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> ((a)[i] == 1 || (a)[i] == 2 || (a)[i] == 3));
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int *a)
{
    int acc = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant acc >= 0;
        loop invariant acc <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> ((a)[i] == 1 || (a)[i] == 2 || (a)[i] == 3));
        loop invariant 2 <= n <= 1000000;
        loop invariant acc <= n;
        loop assigns acc, i;
        loop variant n - i;
    */
    while (i < n)
    {
        int value = a[i];
        if (value == 2)
        {
            acc += 1;
        }
        else if (value == 1)
        {
            if (acc > 0)
            {
                acc -= 1;
            }
        }
        i += 1;
    }
    return acc;
}
