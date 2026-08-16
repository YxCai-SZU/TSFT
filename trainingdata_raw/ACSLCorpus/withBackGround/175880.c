#include <stddef.h>

/*@ predicate element_in_range(int* a, integer n) =
       \forall integer i; 0 <= i < n ==> -100 <= a[i] <= 100;
*/

/*@ predicate max_ge_prefix(int* a, integer i, int max_val) =
       \forall integer k; 0 <= k < i ==> max_val >= a[k];
*/

/*@ predicate min_le_prefix(int* a, integer i, int min_val) =
       \forall integer k; 0 <= k < i ==> min_val <= a[k];
*/

/*@ lemma max_min_relation: 
      \forall int max_val, min_val; max_val >= min_val ==> max_val - min_val >= 0;
*/

/*@
  requires n > 0 && n <= 100;
  requires \valid(a + (0..n-1));
  requires element_in_range(a, n);
  ensures \result >= 0;
  assigns \nothing;
*/
int func(size_t n, int* a) {
    int max_val = a[0];
    int min_val = a[0];
    size_t i = 1;
    
    /*@
      loop invariant 1 <= i <= n;
      loop invariant element_in_range(a, n);
      loop invariant -100 <= max_val <= 100;
      loop invariant -100 <= min_val <= 100;
      loop invariant max_ge_prefix(a, i, max_val);
      loop invariant min_le_prefix(a, i, min_val);
      loop invariant max_val >= min_val;
      loop assigns max_val, min_val, i;
      loop variant n - i;
    */
    while (i < n) {
        size_t idx = i;
        if (a[idx] > max_val) {
            max_val = a[idx];
        }
        if (a[idx] < min_val) {
            min_val = a[idx];
        }
        i++;
    }
    
    //@ assert max_val >= min_val;
    return max_val - min_val;
}
