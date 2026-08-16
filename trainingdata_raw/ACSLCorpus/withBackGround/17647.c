#include <limits.h>

/*@
    predicate valid_array(integer n, int *p) =
        n >= 1 && n <= 200000 &&
        \valid(p + (0..n-1)) &&
        (\forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n) &&
        (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);

    lemma array_properties_preserved:
        \forall integer n, int *p, integer i;
        valid_array(n, p) && 0 <= i <= n ==>
        \forall integer k; 0 <= k < n ==> p[k] >= 1 && p[k] <= n;

    lemma array_distinct_preserved:
        \forall integer n, int *p, integer i;
        valid_array(n, p) && 0 <= i <= n ==>
        \forall integer k, j; 0 <= k < j < n ==> p[k] != p[j];
*/

/*@
    requires valid_array(n, p);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *p)
{
    int cnt = 0;
    int min_bound = INT_MAX;
    int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant cnt >= 0;
        loop invariant cnt <= i;
        loop invariant valid_array(n, p);
        loop invariant i > 0 ==> min_bound <= INT_MAX;
        loop assigns i, cnt, min_bound;
        loop variant n - i;
    */
    while (i < n)
    {
        int pi = p[i];
        
        //@ assert pi >= 1 && pi <= n;
        
        if (min_bound >= pi)
        {
            cnt += 1;
            min_bound = pi;
        }
        
        i += 1;
    }
    
    return cnt;
}
