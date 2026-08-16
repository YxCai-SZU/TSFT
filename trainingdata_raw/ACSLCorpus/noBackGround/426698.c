#include <stddef.h>
#include <stdint.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
  requires (\valid_read((h) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
  ensures \result >= 0;
  ensures \result <= n;
  assigns \nothing;
*/
int func(size_t n, size_t k, const int* h) {
    int ans = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant ans >= 0;
      loop invariant ans <= index;
      loop invariant \forall integer i; 0 <= i < index ==> h[i] >= 1 && h[i] <= 500;
      loop invariant ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
      loop invariant (\valid_read((h) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
      loop assigns ans, index;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (h[index] >= (int)k) {
            ans += 1;
        }
        index += 1;
    }
    return ans;
}
