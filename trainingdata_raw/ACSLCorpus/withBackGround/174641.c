#include <stdbool.h>

/*@ predicate is_odd(integer x) = (x & 1) != 0; */

/*@
  requires n >= 1 && n <= 200000;
  requires \valid(numbers + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> numbers[i] >= 1 && numbers[i] <= 1000000000;
  ensures \result >= 0 && \result <= n;
  assigns \nothing;
*/
int func(int n, int* numbers) {
    int count = 0;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant \forall integer k; 0 <= k < n ==> numbers[k] >= 1 && numbers[k] <= 1000000000;
      loop invariant n >= 1 && n <= 200000;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (is_odd(numbers[i])) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
