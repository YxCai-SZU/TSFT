#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires (\forall integer i, j; 0 <= i <= j < (len) ==> (arr)[i] <= (arr)[j]);
  ensures \result == true <==> (\exists integer i; 0 <= i < (len) && (arr)[i] == (target));
*/
bool search(int *arr, size_t len, int target) {
    size_t low = 0;
    size_t high = len;

    /*@
      loop invariant 0 <= low <= high <= len;
      loop invariant \forall integer i; 0 <= i < low ==> arr[i] < target;
      loop invariant \forall integer i; high <= i < len ==> arr[i] > target;
      loop assigns low, high;
      loop variant high - low;
    */
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        
        if (arr[mid] < target) {
            low = mid + 1;
        } else if (arr[mid] > target) {
            high = mid;
        } else {
            return true;
        }
    }
    return false;
}
