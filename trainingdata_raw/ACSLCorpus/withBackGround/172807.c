#include <stddef.h>

/*@ predicate is_max(integer val, int* arr, integer len, integer idx) =
      idx >= 0 && idx < len && val == arr[idx];
*/

/*@ predicate dominates(integer val, int* arr, integer len, integer bound) =
      \forall integer k; 0 <= k < bound ==> val >= arr[k];
*/

/*@ lemma max_exists: 
      \forall int* arr, integer len, integer bound; 
      len > 0 && 1 <= bound <= len && dominates(arr[0], arr, len, bound) ==>
      \exists integer k; 0 <= k < bound && is_max(arr[0], arr, len, k);
*/

/*@
  requires n > 0;
  requires \valid(arr + (0 .. n-1));
  assigns \nothing;
  ensures dominates(\result, arr, n, n);
  ensures \exists integer i; 0 <= i < n && is_max(\result, arr, n, i);
*/
int max_element(int* arr, size_t n)
{
    int max_val = arr[0];
    size_t i = 1;

    /*@
      loop invariant 1 <= i <= n;
      loop invariant dominates(max_val, arr, n, i);
      loop invariant \exists integer k; 0 <= k < i && is_max(max_val, arr, n, k);
      loop assigns max_val, i;
      loop variant n - i;
    */
    while (i < n) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            //@ assert is_max(max_val, arr, n, i);
        }
        i++;
    }

    return max_val;
}
