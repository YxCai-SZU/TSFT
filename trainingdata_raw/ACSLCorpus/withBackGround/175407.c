#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_valid_array(int *arr, integer n) =
      n > 0 && n <= 100 &&
      \valid(arr + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 0 <= arr[i] && arr[i] <= 100;
*/

/*@ logic integer array_value(int *arr, integer i) = arr[i]; */

/*@ axiomatic MinMax {
      logic integer min(int *arr, integer n) reads arr[0..n-1];
      logic integer max(int *arr, integer n) reads arr[0..n-1];
      
      axiom min_axiom:
        \forall int *arr, integer n; n > 0 ==>
        \exists integer i; 0 <= i < n && min(arr, n) == arr[i] &&
        \forall integer j; 0 <= j < n ==> min(arr, n) <= arr[j];
      
      axiom max_axiom:
        \forall int *arr, integer n; n > 0 ==>
        \exists integer i; 0 <= i < n && max(arr, n) == arr[i] &&
        \forall integer j; 0 <= j < n ==> max(arr, n) >= arr[j];
    }
*/

/*@ lemma diff_exists:
      \forall int *arr, integer n;
      is_valid_array(arr, n) ==>
      \exists integer a, b; 0 <= a < n && 0 <= b < n &&
      (max(arr, n) - min(arr, n)) == array_value(arr, b) - array_value(arr, a);
*/

/*@ requires is_valid_array(arr, (integer)n);
    ensures \result >= 0 && \result <= 100;
    ensures \exists integer a, b; 0 <= a < (integer)n && 0 <= b < (integer)n && 
            \result == array_value(arr, b) - array_value(arr, a);
    assigns \nothing;
*/
int func(size_t n, int *arr) {
    int min_val;
    int max_val;
    size_t i;
    
    min_val = arr[0];
    max_val = arr[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= (integer)n;
        loop invariant \valid(arr + (0 .. (integer)n-1));
        loop invariant \forall integer j; 0 <= j < (integer)n ==> 0 <= arr[j] && arr[j] <= 100;
        loop invariant \forall integer k; 0 <= k < (integer)i ==> min_val <= arr[k];
        loop invariant \forall integer k; 0 <= k < (integer)i ==> max_val >= arr[k];
        loop invariant min_val >= 0;
        loop invariant max_val <= 100;
        loop invariant \exists integer a, b; 0 <= a < (integer)i && 0 <= b < (integer)i && 
                      max_val - min_val == array_value(arr, b) - array_value(arr, a);
        loop assigns i, min_val, max_val;
        loop variant (integer)n - (integer)i;
    */
    while (i < n) {
        int a = arr[i];
        if (a < min_val) {
            min_val = a;
        }
        if (a > max_val) {
            max_val = a;
        }
        i++;
    }
    
    //@ assert \exists integer a, b; 0 <= a < (integer)n && 0 <= b < (integer)n && max_val - min_val == array_value(arr, b) - array_value(arr, a);
    
    return max_val - min_val;
}
