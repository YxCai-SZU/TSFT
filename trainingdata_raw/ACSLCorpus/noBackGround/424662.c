#include <stddef.h>
#include <stdint.h>

/*@ requires \valid_read(arr + (0 .. len-1));
    requires (\forall integer i, j; 0 <= i <= j < (len) ==> (arr)[i] <= (arr)[j]);
    requires len < 0x80000000;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len && arr[i] == x ==> \result > 0;
    ensures \forall integer i; 0 <= i < len && arr[i] != x ==> \result >= 0;
*/
size_t count_elements(int *arr, size_t len, int x) {
    size_t low = 0;
    size_t high = len;
    size_t count = 0;
    size_t i = 0;

    /*@ loop invariant 0 <= low <= high <= len;
        loop invariant (\forall integer i, j; 0 <= i <= j < (len) ==> (arr)[i] <= (arr)[j]);
        loop invariant (\forall integer i; 0 <= i < (low) ==> (arr)[i] < (x));
        loop invariant (\forall integer i; (high) <= i < (len) ==> (arr)[i] > (x));
        loop invariant len < 0x80000000;
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high) {
        size_t mid = (low + high) / 2;
        //@ assert low <= mid < high;
        if (arr[mid] < x) {
            low = mid + 1;
        } else if (arr[mid] > x) {
            high = mid;
        } else {
            break;
        }
    }

    i = low;
    /*@ loop invariant ((low) <= (i) <= (high) &&
      (count) <= (size_t)((i) - (low)) &&
      \forall integer k; (low) <= k < (i) ==> ((arr)[k] == (x) ==> (count) > 0) &&
      \forall integer k; (low) <= k < (i) ==> ((arr)[k] != (x) ==> (count) >= 0));
        loop invariant len < 0x80000000;
        loop assigns i, count;
        loop variant high - i;
    */
    while (i < high) {
        if (arr[i] == x) {
            count++;
        }
        i++;
    }

    return count;
}
