#include <stdbool.h>
/*@
    requires \valid_read(A + (0 .. n-1));
    requires (\forall integer i, j; 0 <= i <= j < (n) ==> (A)[i] <= (A)[j]);
    requires n >= 0 && n < 0x80000000;
    ensures \result == 1 <==> (\exists integer i; 0 <= i < (n) && (A)[i] == (x));
    ensures \result == 0 <==> !(\exists integer i; 0 <= i < (n) && (A)[i] == (x));
    assigns \nothing;
*/
bool contains_num(int *A, int n, int x) {
    int low = 0;
    int high = n;
    /*@
        loop invariant 0 <= low <= high <= n;
        loop invariant (\forall integer i, j; 0 <= i <= j < (n) ==> (A)[i] <= (A)[j]);
        loop invariant (\forall integer k; 0 <= k < (low) ==> (A)[k] < (x));
        loop invariant (\forall integer k; (high) <= k < (n) ==> (A)[k] > (x));
        loop invariant (\exists integer i; 0 <= i < (n) && (A)[i] == (x)) ==> (\exists integer j; (low) <= j < (high) && (A)[j] == (x));
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high) {
        int mid = (low + high) / 2;
        //@ assert low <= mid < high;
        if (A[mid] < x) {
            //@ assert \forall integer k; low <= k <= mid ==> A[k] < x;
            low = mid + 1;
        } else if (A[mid] > x) {
            //@ assert \forall integer k; mid <= k < high ==> A[k] > x;
            high = mid;
        } else {
            //@ assert (\exists integer i; 0 <= i < (n) && (A)[i] == (x));
            return true;
        }
    }
    //@ assert !(\exists integer j; (low) <= j < (high) && (A)[j] == (x));
    return false;
}
