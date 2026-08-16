#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) > 0 && (n) <= 100000 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 1 <= (h)[i] <= 1000000000);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int64_t func(size_t n, int64_t *h)
{
    int64_t ans = 0;
    int64_t cur_h = h[0];
    int64_t cur_n = 0;
    size_t i = 1;

    //@ assert 1 <= i <= n;
    //@ assert 0 <= cur_n <= i;
    //@ assert 0 <= ans <= i;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant 0 <= cur_n <= i;
        loop invariant 0 <= ans <= i;
        loop assigns i, cur_h, cur_n, ans;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert 0 <= i < n;
        if (h[i] <= cur_h)
        {
            cur_n = cur_n + 1;
            //@ assert 0 <= cur_n <= i+1;
        }
        else
        {
            cur_h = h[i];
            cur_n = 0;
            //@ assert 0 <= cur_n <= i+1;
        }
        //@ assert 0 <= cur_n <= i+1;
        
        if (ans > cur_n)
        {
            //@ assert ans == (((ans) > (cur_n)) ? (ans) : (cur_n));
        }
        else
        {
            ans = cur_n;
            //@ assert ans == (((ans) > (cur_n)) ? (ans) : (cur_n));
        }
        //@ assert 0 <= ans <= i+1;
        
        i = i + 1;
        //@ assert 0 <= ans <= i;
        //@ assert 0 <= cur_n <= i;
    }
    
    //@ assert 0 <= ans <= n;
    return ans;
}
