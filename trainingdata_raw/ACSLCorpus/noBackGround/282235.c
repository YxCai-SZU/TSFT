#include <stdbool.h>
#include <stddef.h>

/*@
    requires (2 <= (k) <= 1000000 &&
        2 <= (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        (\forall integer i; 0 <= i < (n) ==> 0 <= (a)[i] < (k)) &&
        (\forall integer i; 0 <= i < (n)-1 ==> (a)[i] < (a)[i+1]));
    ensures \result >= 0 && \result <= k;
    assigns \nothing;
*/
int func(int k, int n, int *a)
{
    int dist = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= n-1;
        loop invariant dist >= 0;
        loop invariant dist <= k;
        loop invariant \forall integer j; 0 <= j < i ==> 0 <= a[j] < k;
        loop invariant \forall integer j; 0 <= j < i-1 ==> a[j] < a[j+1];
        loop invariant dist <= a[i] - a[0];
        loop assigns dist, i;
        loop variant n - i;
    */
    while (i < n - 1)
    {
        int d;
        if (a[i + 1] - a[i] > dist)
        {
            d = a[i + 1] - a[i];
        }
        else
        {
            d = dist;
        }
        dist = d;
        i++;
        
        //@ assert dist >= 0;
    }
    
    int m;
    if (a[0] + dist < k - a[n - 1])
    {
        m = a[0] + dist;
    }
    else
    {
        m = k - a[n - 1];
    }
    
    int ans = k - m;
    
    //@ assert ans >= 0;
    //@ assert ans <= k;
    
    return ans;
}
