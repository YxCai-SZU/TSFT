#include <stdbool.h>
#include <stddef.h>

/*@
  requires n <= 100000;
  requires \valid(arr + (0..n-1));
  requires (\forall size_t i; 0 <= i < (n) ==> 1 <= (arr)[i] <= (n));
  requires (\forall size_t i, j; 0 <= i < j < (n) ==> (arr)[i] != (arr)[j]);
  requires (2 <= (k) && (k) <= (n) && (n) <= 100000);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
size_t func(size_t n, size_t k, const size_t arr[]) {
    size_t ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ans <= i;
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        if (i + 1 < n && arr[i] + 1 == arr[i + 1]) {
            size_t count = 1;
            size_t j = i;
            
            /*@
              loop invariant i <= j <= n - 1;
              loop invariant count == j - i + 1;
              loop assigns j, count;
              loop variant n - j - 1;
            */
            while (j < n - 1 && arr[j] + 1 == arr[j + 1]) {
                count += 1;
                j += 1;
            }
            
            //@ assert count >= 1;
            if (count >= k) {
                ans += 1;
            }
        }
        i += 1;
    }
    
    //@ assert ans <= n;
    return ans;
}
