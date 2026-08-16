#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(array + (0 .. len-1));
    requires (\forall integer i, j; 0 <= i <= j < (len) ==> (array)[i] <= (array)[j]);
    ensures \result <==> (\exists integer k; 0 <= k < (len) && (array)[k] == (target));
    assigns \nothing;
*/
bool contains_number(int* array, size_t len, int target) {
    if (len == 0) {
        return false;
    }

    size_t start = 0;
    size_t end = len;

    //@ assert \forall integer i; 0 <= i < len ==> array[i] <= array[i];
    //@ assert (\forall integer i, j; 0 <= i <= j < (len) ==> (array)[i] <= (array)[j]);
    //@ assert \forall integer k; 0 <= k < len && array[k] == target ==> (\exists integer k; 0 <= k < (len) && (array)[k] == (target));

    /*@
        loop invariant 0 <= start <= end <= len;
        loop invariant (\forall integer i, j; 0 <= i <= j < (len) ==> (array)[i] <= (array)[j]);
        loop invariant \forall integer k; (0 <= k < start || end <= k < len) ==> array[k] != target;
        loop assigns start, end;
        loop variant end - start;
    */
    while (start < end) {
        size_t mid = start + (end - start) / 2;
        
        if (array[mid] == target) {
            return true;
        } else if (array[mid] < target) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    
    return false;
}
