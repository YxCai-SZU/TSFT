#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid_read(A+(0..len-1));
    requires (\forall integer i, j; 0 <= i <= j < (len) ==> (A)[i] <= (A)[j]);
    requires len < 0x80000000;
    ensures \result == 1 <==> (\exists integer i; 0 <= i < (len) && (A)[i] == (x));
*/
bool does_exist(int* A, size_t len, int x) {
    size_t low = 0;
    size_t high = len;

    /*@ loop invariant 0 <= low <= high <= len;
        loop invariant (\forall integer i, j; 0 <= i <= j < (len) ==> (A)[i] <= (A)[j]);
        loop invariant (\forall integer k; 0 <= k < (low) ==> (A)[k] < (x));
        loop invariant (\forall integer k; (high) <= k < (len) ==> (A)[k] > (x));
        loop invariant len < 0x80000000;
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        
        //@ assert mid < len;
        
        if (A[mid] < x) {
            //@ assert \forall integer k; 0 <= k <= mid ==> A[k] < x;
            low = mid + 1;
        } else if (A[mid] > x) {
            //@ assert \forall integer k; mid <= k < len ==> A[k] > x;
            high = mid;
        } else {
            //@ assert (\exists integer i; 0 <= i < (len) && (A)[i] == (x));
            return true;
        }
    }
    
    //@ assert !(\exists integer i; 0 <= i < (len) && (A)[i] == (x));
    return false;
}
