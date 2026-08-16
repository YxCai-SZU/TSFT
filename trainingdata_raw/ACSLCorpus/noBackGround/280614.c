#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
    ensures 1 <= \result && \result <= n;
    assigns \nothing;
*/
int32_t func(size_t n, int64_t* a)
{
    int32_t cnt = 1;
    int64_t v = a[0];
    size_t i = 1;

    /*@
        loop invariant 1 <= i && i <= n;
        loop invariant 1 <= cnt && cnt <= i;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] <= v;
        loop assigns i, cnt, v;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert 0 <= i && i < n;
        
        if (a[i] >= v)
        {
            cnt = cnt + 1;
            v = a[i];
        }
        
        i = i + 1;
    }
    
    //@ assert 1 <= cnt && cnt <= n;
    return cnt;
}
