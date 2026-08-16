#include <stddef.h>
#include <stdbool.h>

/*@
  requires ((n) > 0 && (n) <= 20 &&
      \valid((h) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 100);
  ensures \result >= 0;
*/
int func(size_t n, int *h)
{
    int cur_h = 0;
    size_t index = 0;
    int ans = 0;

    /*@
      loop invariant (0 <= (index) <= (n) &&
      0 <= (cur_h) <= 100 &&
      ((index) > 0 ==> \forall integer k; 0 <= k < (index) ==> (cur_h) >= (h)[k]));
      loop assigns cur_h, index;
      loop variant n - index;
    */
    while (index < n)
    {
        //@ assert 0 <= index < n;
        if (cur_h < h[index]) {
            cur_h = h[index];
        }
        index += 1;
    }
    
    ans = cur_h;
    
    //@ assert cur_h >= 0;
    
    return ans;
}
