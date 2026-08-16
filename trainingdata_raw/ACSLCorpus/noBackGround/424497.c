#include <stdbool.h>

/*@ requires len > 0;
    requires (\forall integer i, j; 0 <= i <= j < (len) ==> (A)[i] <= (A)[j]);
    ensures \result == true ==> (\exists integer i; 0 <= i < (len) && (A)[i] == (x));
    ensures \result == false ==> (\forall integer i; 0 <= i < (len) ==> (A)[i] != (x));
*/
bool does_exist(int* A, int len, int x) {
    int low = 0;
    int high = len;
    /*@ loop invariant 0 <= low <= high <= len;
        loop invariant \forall integer i; 0 <= i < low ==> A[i] != x;
        loop invariant \forall integer i; high <= i < len ==> A[i] != x;
        loop invariant (\forall integer i, j; 0 <= i <= j < (len) ==> (A)[i] <= (A)[j]);
        loop invariant len > 0;
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high) {
        int mid = low + (high - low) / 2;
        //@ assert low <= mid < high;
        if (A[mid] < x) {
            low = mid + 1;
        } else if (A[mid] > x) {
            high = mid;
        } else {
            //@ assert (\exists integer i; 0 <= i < (len) && (A)[i] == (x));
            return true;
        }
    }
    //@ assert (\forall integer i; 0 <= i < (len) ==> (A)[i] != (x));
    return false;
}
