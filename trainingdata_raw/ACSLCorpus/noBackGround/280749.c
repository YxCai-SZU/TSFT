#include <stdint.h>
#include <stddef.h>

/*@
  requires ((n) >= 2 && (n) <= 100000 &&
      \valid((h) + (0..(n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 10000);
  ensures \result >= 0 && \result <= n-1;
*/
int64_t func(size_t n, int64_t *h)
{
    int64_t ans = 0;
    int64_t cur = 0;
    int64_t prev = 0;
    size_t i = 1;
    //@ assert 1 <= i <= n;
    //@ assert 0 <= cur <= i-1;
    //@ assert 0 <= ans <= i-1;
    
    /*@ loop invariant 1 <= i <= n;
        loop invariant 0 <= cur <= i-1;
        loop invariant 0 <= ans <= i-1;
        loop invariant ((n) >= 2 && (n) <= 100000 &&
      \valid((h) + (0..(n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 10000);
        loop assigns i, cur, ans, prev;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] <= prev) {
            cur = cur + 1;
        } else {
            cur = 0;
        }
        //@ assert 0 <= cur <= i;
        
        if (ans < cur) {
            ans = cur;
        }
        //@ assert 0 <= ans <= i;
        
        prev = h[i];
        i = i + 1;
        //@ assert 0 <= cur <= i-1;
        //@ assert 0 <= ans <= i-1;
    }
    //@ assert i == n;
    //@ assert 0 <= ans <= n-1;
    return ans;
}
