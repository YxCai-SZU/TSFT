#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_non_zero(int *arr, integer len) =
      \forall integer k; 0 <= k < len ==> arr[k] != 0;
*/

/*@ predicate valid_range(int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 1000000000;
*/

/*@ lemma range_preserved:
      \forall int *arr, integer len, integer idx;
        0 <= idx <= len && valid_range(arr, len) ==>
        valid_range(arr, idx);
*/

/*@
  requires length >= 0;
  requires \valid(test_slice + (0 .. length-1));
  assigns \nothing;
  ensures \result == true <==> is_non_zero(test_slice, length);
*/
bool check_no_zero(int *test_slice, int length) {
    int i = 0;
    /*@ loop invariant 0 <= i <= length;
        loop invariant \forall integer k; 0 <= k < i ==> test_slice[k] != 0;
        loop assigns i;
        loop variant length - i;
    */
    while (i < length) {
        //@ assert i >= 0 && i < length;
        if (test_slice[i] == 0) {
            return false;
        }
        i++;
    }
    return true;
}

/*@
  requires 1 <= n <= 200000;
  requires \valid(v + (0 .. n-1));
  requires valid_range(v, n);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(int n, int *v) {
    int before = 0;
    int res = 0;
    int index = 0;
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= res <= index;
        loop invariant valid_range(v, index);
        loop invariant before >= 0;
        loop assigns before, res, index;
        loop variant n - index;
    */
    while (index < n) {
        int a = v[index];
        //@ assert 1 <= a <= 1000000000;
        if (before >= a) {
            res++;
        } else {
            before = a;
        }
        index++;
    }
    return res;
}
