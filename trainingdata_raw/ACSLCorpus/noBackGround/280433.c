#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
  requires 1 <= k <= 100;
  requires 1 <= n <= 100;
  requires \valid(result + (0..n-1));
  ensures (\forall integer i; 0 <= i < (n) ==> 1 <= (result)[i] <= (k));
  assigns result[0..n-1];
*/
void func(uint32_t k, uint32_t n, uint32_t *result) {
    uint32_t i = 0;
    uint32_t idx = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer j; 0 <= j < i ==> result[j] == k;
      loop assigns i, result[0..n-1];
      loop variant n - i;
    */
    while (i < n) {
        //@ assert (0 <= (i) < (n));
        result[i] = k;
        i = i + 1;
    }
    
    /*@
      loop invariant 0 <= idx <= n;
      loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (result)[i] <= (k));
      loop assigns idx, result[0..n-1];
      loop variant n - idx;
    */
    while (idx < n) {
        //@ assert (0 <= (idx) < (n));
        uint32_t new_value = (result[idx] == 1) ? k : (result[idx] - 1);
        //@ assert 1 <= new_value <= k;
        result[idx] = new_value;
        idx = idx + 1;
    }
}
