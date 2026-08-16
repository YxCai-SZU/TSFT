#include <stdbool.h>
#include <stddef.h>

/*@
    predicate sorted(int *arr, integer len) =
        \forall integer i, j; 0 <= i <= j < len ==> arr[i] <= arr[j];

    predicate exists_at{L}(int *arr, integer len, integer target) =
        \exists integer i; 0 <= i < len && arr[i] == target;

    predicate lower_bound{L}(int *arr, integer low, integer target) =
        \forall integer k; 0 <= k < low ==> arr[k] < target;

    predicate upper_bound{L}(int *arr, integer high, integer len, integer target) =
        \forall integer k; high <= k < len ==> arr[k] > target;

    lemma bounds_preserve_sorted:
        \forall int *arr, integer len, integer low, integer high;
        sorted(arr, len) && 0 <= low <= high <= len ==>
        sorted(arr, len);
*/


bool search(const int *arr, size_t len, int target) {
    size_t low = 0;
    size_t high = len;

    
    while (low < high) {
        size_t mid = low + (high - low) / 2;

        //@ assert mid < len;
        if (arr[mid] < target) {
            //@ assert \forall integer k; 0 <= k < mid+1 ==> arr[k] < target;
            low = mid + 1;
        } else if (arr[mid] > target) {
            //@ assert \forall integer k; mid <= k < len ==> arr[k] > target;
            high = mid;
        } else {
            //@ assert exists_at{Here}(arr, len, target);
            return true;
        }
    }

    //@ assert !exists_at{Here}(arr, len, target);
    return false;
}
