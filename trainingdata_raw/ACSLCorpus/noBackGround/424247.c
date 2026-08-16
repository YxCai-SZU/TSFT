#include <stdint.h>
#include <stdbool.h>

/*@
    requires ((n) > 0 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(uint32_t n, int64_t *a)
{
    int64_t ans = 0;
    int64_t prev_height = 0;
    uint32_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= ((i) * 1000000000);
        loop invariant 0 <= prev_height <= 1000000000;
        loop invariant ((n) > 0 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
        loop invariant \forall integer k; 0 <= k < i ==> prev_height >= a[k];
        loop invariant \forall integer k; 0 <= k < i ==> ans >= a[k] - prev_height;
        loop assigns ans, prev_height, i;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert 0 <= i < n;
        //@ assert a[i] > 0 && a[i] <= 1000000000;
        
        if (a[i] - prev_height < 0)
        {
            //@ assert prev_height - a[i] >= 0;
            ans += prev_height - a[i];
            //@ assert ans >= 0;
        }
        else
        {
            prev_height = a[i];
            //@ assert prev_height >= 0;
        }
        
        i++;
        //@ assert i <= n;
    }
    
    //@ assert ans >= 0;
    return ans;
}
