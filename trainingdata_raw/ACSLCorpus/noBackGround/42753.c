#include <stdint.h>
#include <stddef.h>

/*@
  requires n >= 2 && n <= 200000;
  requires \valid(a + (0 .. n-1));
  requires \forall size_t i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 1000000;
  ensures \result >= 0;
*/
int64_t func(size_t n, int64_t *a)
{
    int64_t ans = 0;
    int64_t x = 0;
    size_t i = 0;
    
    //@ assert (0 <= (i) && (i) <= (n) &&       (ans) >= 0 &&       \valid((a) + (0 .. (n)-1)) &&       \forall size_t k; 0 <= k < (n) ==> 1 <= (a)[k] && (a)[k] <= 1000000);
    
    /*@ loop invariant (0 <= (i) && (i) <= (n) &&
      (ans) >= 0 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall size_t k; 0 <= k < (n) ==> 1 <= (a)[k] && (a)[k] <= 1000000);
        loop assigns i, x, ans;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i && i < n;
        x ^= a[i];
        //@ assert ans >= 0;
        ans = (x > ans) ? x : ans;
        //@ assert ans >= 0;
        i += 1;
        //@ assert (0 <= (i) && (i) <= (n) &&       (ans) >= 0 &&       \valid((a) + (0 .. (n)-1)) &&       \forall size_t k; 0 <= k < (n) ==> 1 <= (a)[k] && (a)[k] <= 1000000);
    }
    
    //@ assert ans >= 0;
    return ans;
}
