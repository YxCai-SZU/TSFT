#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid_read(array + (0 .. len-1));
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (array)[i] <= (array)[j]);
    assigns \nothing;
    ensures \result == true <==> \exists integer i; 0 <= i < len && array[i] == target;
    ensures \result == false <==> \forall integer i; 0 <= i < len ==> array[i] != target;
*/
bool contains_number(unsigned int *array, size_t len, unsigned int target) {
    // Variable declarations at top of scope
    size_t start;
    size_t end;
    size_t mid;
    bool result;

    if (len == 0) {
        //@ assert \forall integer i; 0 <= i < len ==> array[i] != target;
        result = false;
        return result;
    }

    //@ assert ((len) > 0);
    start = 0;
    end = len;

    /*@ loop invariant 0 <= start <= end <= len;
        loop invariant \forall integer i; 0 <= i < start ==> array[i] < target;
        loop invariant \forall integer i; end <= i < len ==> array[i] > target;
        loop assigns start, end, mid;
        loop variant end - start;
    */
    while (start < end) {
        mid = start + (end - start) / 2;

        //@ assert start <= mid < end;

        if (array[mid] == target) {
            //@ assert (0 <= (mid) < (len) && (array)[(mid)] == (target));
            result = true;
            return result;
        } else if (array[mid] < target) {
            //@ assert \forall integer i; 0 <= i <= mid ==> array[i] < target;
            start = mid + 1;
        } else {
            //@ assert \forall integer i; mid <= i < len ==> array[i] > target;
            end = mid;
        }
    }

    //@ assert \forall integer i; 0 <= i < len ==> array[i] != target;
    result = false;
    return result;
}
