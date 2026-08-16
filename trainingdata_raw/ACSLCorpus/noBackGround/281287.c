#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid_read(array + (0 .. length-1));
    requires (\forall integer i, j; 0 <= i <= j < (length) ==> (array)[i] <= (array)[j]);
    ensures \result == 1 <==> (\exists integer i; 0 <= i < (length) && (array)[i] == (target));
    assigns \nothing;
*/
bool contains_number(int *array, size_t length, int target) {
    size_t start = 0;
    size_t end = length;
    
    /*@ loop invariant 0 <= start <= end <= length;
        loop invariant \forall integer i; 0 <= i < length && array[i] == target ==> start <= i < end;
        loop assigns start, end;
        loop variant end - start;
    */
    while (start < end) {
        size_t mid = start + (end - start) / 2;
        
        if (array[mid] == target) {
            //@ assert (\exists integer i; 0 <= i < (length) && (array)[i] == (target));
            return true;
        } else if (array[mid] < target) {
            //@ assert \forall integer i; 0 <= i < length && array[i] == target ==> (mid + 1) <= i < end;
            start = mid + 1;
        } else {
            //@ assert \forall integer i; 0 <= i < length && array[i] == target ==> start <= i < mid;
            end = mid;
        }
    }
    
    //@ assert !(\exists integer i; 0 <= i < (length) && (array)[i] == (target));
    return false;
}
