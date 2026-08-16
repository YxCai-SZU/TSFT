#include <stdbool.h>
#include <stddef.h>

/*@ predicate sorted(int *arr, integer len) =
      \forall integer i, j; 0 <= i <= j < len ==> arr[i] <= arr[j];
*/

/*@ predicate exists_at(int *arr, integer len, integer x) =
      \exists integer k; 0 <= k < len && arr[k] == x;
*/

/*@ lemma sorted_preserved:
      \forall int *arr, integer len;
      sorted(arr, len) ==> sorted(arr, len);
*/

/*@ lemma length_in_range:
      \forall integer len;
      len >= 0 ==> len >= 0;
*/

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires sorted(arr, len);
  requires len >= 0;
  ensures \result == true <==> exists_at(arr, len, x);
  assigns \nothing;
*/
bool contains_number(int *arr, size_t len, int x) {
    size_t low = 0;
    size_t high = len;

    /*@
      loop invariant 0 <= low <= high <= len;
      loop invariant sorted(arr, len);
      loop invariant \forall integer k; 0 <= k < low ==> arr[k] < x;
      loop invariant \forall integer k; high <= k < len ==> arr[k] > x;
      loop invariant len >= 0;
      loop assigns low, high;
      loop variant high - low;
    */
    while (low < high) {
        size_t mid = low + (high - low) / 2;

        //@ assert low <= mid < high;

        if (arr[mid] < x) {
            low = mid + 1;
        } else if (arr[mid] > x) {
            high = mid;
        } else {
            //@ assert exists_at(arr, len, x);
            return true;
        }
    }

    //@ assert !exists_at(arr, len, x);
    return false;
}
