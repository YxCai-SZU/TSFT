#include <stdbool.h>
#include <stddef.h>

/*@ predicate sorted(int *arr, integer len) =
      \forall integer i, j; 0 <= i <= j < len ==> arr[i] <= arr[j];
*/

/*@ predicate bounded(int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> 0 <= arr[i] <= 10000;
*/

/*@ predicate exists_at(int *arr, integer len, int target) =
      \exists integer i; 0 <= i < len && arr[i] == target;
*/

/*@ lemma sorted_preserved:
      \forall int *arr, integer len, integer start, integer end, int target;
      sorted(arr, len) && bounded(arr, len) &&
      0 <= start <= end <= len &&
      (\forall integer i; 0 <= i < start ==> arr[i] < target) &&
      (\forall integer i; end <= i < len ==> arr[i] > target) ==>
      (\forall integer i; 0 <= i < len && arr[i] == target ==> start <= i < end);
*/

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires sorted(arr, len);
  requires bounded(arr, len);
  ensures \result == true <==> exists_at(arr, len, target);
  ensures \result == false <==> !exists_at(arr, len, target);
  assigns \nothing;
*/
bool contains_element(int *arr, size_t len, int target) {
    if (len == 0) {
        return false;
    }

    size_t start = 0;
    size_t end = len;

    /*@
      loop invariant 0 <= start <= end <= len;
      loop invariant \forall integer i; 0 <= i < start ==> arr[i] < target;
      loop invariant \forall integer i; end <= i < len ==> arr[i] > target;
      loop invariant sorted(arr, len);
      loop invariant bounded(arr, len);
      loop assigns start, end;
      loop variant end - start;
    */
    while (start < end) {
        size_t mid = start + (end - start) / 2;
        
        //@ assert 0 <= mid < len;
        
        if (arr[mid] == target) {
            //@ assert exists_at(arr, len, target);
            return true;
        } else if (arr[mid] < target) {
            //@ assert \forall integer i; 0 <= i <= mid ==> arr[i] < target;
            start = mid + 1;
        } else {
            //@ assert \forall integer i; mid <= i < len ==> arr[i] > target;
            end = mid;
        }
    }
    
    //@ assert \forall integer i; 0 <= i < len ==> arr[i] != target;
    return false;
}
