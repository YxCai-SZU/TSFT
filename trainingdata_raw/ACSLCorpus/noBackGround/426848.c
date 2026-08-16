#include <stddef.h>
#include <stdbool.h>

/*@
  requires (1 <= (n) <= 20);
  requires \valid_read(h + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((h)[i]) <= 100));
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(int n, int *h) {
    int max_h = 0;
    int res = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= res <= index;
      loop invariant 0 <= max_h <= 100;
      loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> (1 <= (h[i]) <= 100);
      loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((h)[i]) <= 100));
      loop assigns max_h, res, index;
    */
    while (index < n) {
        int a = h[index];
        if (a < max_h) {
            res += 1;
        } else {
            max_h = a;
        }
        index += 1;
    }
    return res;
}
