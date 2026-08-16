#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    requires 1 <= x <= n-1;
    requires \valid(a+(0..m-1));
    requires \valid(b+(0..n-2));
    requires (\forall integer i; 0 <= i < (m) ==> 1 <= (a)[i] <= (n));
    requires (\forall integer i; 0 <= i < (n)-1 ==> 1 <= (b)[i] <= (n));
    ensures 0 <= \result <= m;
*/
int func(int n, int m, int x, int *a, int *b)
{
    int l = 0;
    int r = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant 0 <= l <= i;
        loop invariant 0 <= r <= i;
        loop assigns i, l, r;
    */
    while (i < m)
    {
        int value = a[i];
        //@ assert 1 <= value <= n;
        
        if (value < x)
        {
            l = l + 1;
        }
        
        if (value > x)
        {
            r = r + 1;
        }
        
        i = i + 1;
    }
    
    int min_val = (l < r) ? l : r;
    //@ assert min_val == ((l) < (r) ? (l) : (r));
    
    return min_val;
}
