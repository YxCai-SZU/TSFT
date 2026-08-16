#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_length(integer len) = 0 <= len < 0x80000000; */

/*@ predicate element_in_range(int *arr, integer len, integer idx) =
      0 <= idx < len ==> arr[idx] < 0x80000000; */

/*@ predicate all_elements_in_range(int *arr, integer len) =
      \forall integer j; 0 <= j < len ==> arr[j] < 0x80000000; */

/*@ predicate count_nonnegative(integer cnt) = cnt >= 0; */

/*@ predicate count_bounded(integer cnt, integer len) = cnt <= len; */

/*@ predicate negative_exists_implies_count_positive(int *arr, integer len, integer cnt) =
      \forall integer j; 0 <= j < len && arr[j] < 0 ==> cnt > 0; */

/*@ lemma loop_invariant_maintained:
      \forall int *arr, integer len, integer i, integer cnt;
        0 <= i <= len &&
        cnt >= 0 &&
        cnt <= i &&
        negative_exists_implies_count_positive(arr, i, cnt) &&
        is_valid_length(len) &&
        all_elements_in_range(arr, len)
      ==>
        (i < len ==> (
          (arr[i] < 0 ==> cnt + 1 >= 0) &&
          (arr[i] < 0 ==> cnt + 1 <= i + 1) &&
          (arr[i] < 0 ==> negative_exists_implies_count_positive(arr, i + 1, cnt + 1)) &&
          (arr[i] >= 0 ==> cnt >= 0) &&
          (arr[i] >= 0 ==> cnt <= i + 1) &&
          (arr[i] >= 0 ==> negative_exists_implies_count_positive(arr, i + 1, cnt))
        )); */

/*@
  requires \valid(nums + (0 .. len-1));
  requires is_valid_length(len);
  requires all_elements_in_range(nums, len);
  assigns \nothing;
  ensures count_nonnegative(\result);
  ensures count_bounded(\result, len);
  ensures negative_exists_implies_count_positive(nums, len, \result);
*/
int count_negativenum(int *nums, int len) {
    int count = 0;
    int i = 0;

    /*@
      loop invariant 0 <= i <= len;
      loop invariant count_nonnegative(count);
      loop invariant count_bounded(count, i);
      loop invariant negative_exists_implies_count_positive(nums, i, count);
      loop invariant is_valid_length(len);
      loop invariant all_elements_in_range(nums, len);
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len) {
        int x = nums[i];
        if (x < 0) {
            //@ assert x < 0;
            count += 1;
        }
        i += 1;
    }
    return count;
}
