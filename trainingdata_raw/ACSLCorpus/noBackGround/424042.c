#include <stdbool.h>

/*@
    requires 3 <= n && n <= 100;
    requires \valid(p + (0 .. n-1));
    requires ((n) >= 3 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= 20);
    requires 1 <= a && a < b && b < 20;
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int a, int b, int *p)
{
    int count = 0;
    int p2 = 0;
    int p3 = 0;
    int i = 0;

    /*@
        loop invariant (0 <= (i) <= (n) &&
        (count) >= 0 && (p2) >= 0 && (p3) >= 0 &&
        (count) <= (i) && (p2) <= (i) && (p3) <= (i) &&
        (((n)) >= 3 && ((n)) <= 100 &&
        \forall integer i; 0 <= i < ((n)) ==> ((p))[i] >= 1 && ((p))[i] <= 20) &&
        1 <= (a) && (a) < (b) && (b) < 20);
        loop invariant i <= n;
        loop assigns i, count, p2, p3;
        loop variant n - i;
    */
    while (i < n)
    {
        int pi = p[i];
        if (pi <= a)
        {
            p2 += 1;
        }
        else if (pi <= b)
        {
            p3 += 1;
        }
        else
        {
            count += 1;
        }
        i += 1;
    }

    //@ assert p2 >= 0 && p3 >= 0;
    return (p2 < p3) ? p2 : p3;
}
