#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= x <= 10000;
    requires \valid(lengths + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (lengths)[i] <= 100);
    ensures 1 <= \result <= n + 1;
    ensures \result == 1 || x >= lengths[\result - 2];
*/
int func(int n, int x, int *lengths)
{
    int di = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant 0 <= di <= x;
        loop invariant i == 1 || x >= lengths[i - 2];
        loop assigns i, di;
        loop variant n - i;
    */
    while (i <= n)
    {
        int l = lengths[i - 1];
        di += l;

        if (x < di)
        {
            //@ assert i == 1 || x >= lengths[i - 2];
            return i;
        }
        else if (i == n)
        {
            return i + 1;
        }
        i += 1;
    }
    return n + 1;
}
