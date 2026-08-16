#include <stdbool.h>
#include <stdint.h>

/*@
  requires n >= 1 && n <= 100000;
  requires k >= 1 && k <= 500;
  requires \valid(heights + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
unsigned int func(unsigned int n, unsigned int k, unsigned int *heights) {
    unsigned int num = 0;
    unsigned int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= num <= index;
      loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
      loop invariant (\forall integer i; 0 <= i < (index) ==> ((heights)[i] >= (k) ==> (num) > 0));
      loop assigns num, index;
      loop variant n - index;
    */
    while (index < n) {
        unsigned int h = heights[index];
        if (h >= k) {
            num += 1;
        }
        index += 1;
    }
    return num;
}
