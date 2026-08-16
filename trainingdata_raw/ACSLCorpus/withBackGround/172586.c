#include <stddef.h>
#include <stdbool.h>

/*@ predicate in_range(integer value, integer low, integer high) =
      low <= value <= high;
*/

/*@ predicate all_in_range(int *arr, integer len, integer low, integer high) =
      \forall integer i; 0 <= i < len ==> in_range(arr[i], low, high);
*/

/*@ predicate count_positive(int *arr, integer len, integer low, integer high, integer cnt) =
      \forall integer i; 0 <= i < len && in_range(arr[i], low, high) ==> cnt > 0;
*/

/*@ lemma range_validity: \forall integer m, integer n; m <= n ==> \true; */

/*@
  requires m <= n;
  requires \valid_read(arr + (0 .. len-1));
  requires all_in_range(arr, len, m, n);
  assigns \nothing;
  ensures 0 <= \result <= len;
  ensures count_positive(arr, len, m, n, \result);
*/
size_t count_in_range(const int *arr, size_t len, int m, int n) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant 0 <= count <= i;
      loop invariant all_in_range(arr, len, m, n);
      loop invariant m <= n;
      loop invariant count_positive(arr, i, m, n, count);
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert all_in_range(arr, len, m, n);
        if (arr[i] <= n && arr[i] >= m) {
            count++;
        }
        i++;
    }
    return count;
}

int main() {
    return 0;
}
