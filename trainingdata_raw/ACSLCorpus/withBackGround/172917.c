#include <stddef.h>
#include <limits.h>

/*@ predicate is_in_range(integer i, integer m, integer n) =
      m <= i && i <= n;
*/

/*@ predicate is_max_in_range(int *arr, integer m, integer n, integer max_val) =
      \exists integer i; m <= i <= n && arr[i] == max_val &&
      (\forall integer j; m <= j <= n ==> arr[j] <= max_val);
*/

/*@ lemma range_bounds_lemma:
      \forall int *arr, integer m, integer n, integer len;
      m < len && n < len && m <= n ==>
      (\forall integer i; m <= i <= n ==> i < len);
*/

/*@ requires m < len && n < len && m <= n;
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures is_max_in_range(arr, m, n, \result);
*/
int max_range_list(const int *arr, size_t len, size_t m, size_t n) {
    //@ assert m < len;
    //@ assert n < len;
    //@ assert m <= n;
    
    int max = arr[m];
    size_t i = m + 1;
    
    /*@ loop invariant m < len && n < len;
        loop invariant m <= i;
        loop invariant i <= n + 1;
        loop invariant \exists integer j; m <= j < i && arr[j] == max;
        loop invariant \forall integer j; m <= j < i ==> arr[j] <= max;
        loop assigns max, i;
        loop variant n - i + 1;
    */
    while (i <= n) {
        if (arr[i] > max) {
            max = arr[i];
        }
        i++;
    }
    
    //@ assert is_max_in_range(arr, m, n, max);
    return max;
}
