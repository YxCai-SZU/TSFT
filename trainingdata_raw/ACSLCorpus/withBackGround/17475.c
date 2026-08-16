#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_params(integer n, integer k, int *h) =
      n >= 1 && n <= 100000 &&
      k >= 1 && k <= 500 &&
      \valid(h + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@ requires is_valid_params(n, k, h);
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n ==> 
              (h[i] >= k ==> \result >= 1) && 
              (h[i] < k ==> \result <= n - 1);
    assigns \nothing;
*/
int func(int n, int k, int *h) {
    int num = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= num <= index;
        loop invariant index > 0 ==> 
               \forall integer i; 0 <= i < index ==> 
                 (h[i] >= k ==> num >= 1) && 
                 (h[i] < k ==> num <= index - 1);
        loop assigns num, index;
        loop variant n - index;
    */
    while (index < n) {
        int i = h[index];
        if (i >= k) {
            num = num + 1;
        }
        index = index + 1;
    }
    
    return num;
}
