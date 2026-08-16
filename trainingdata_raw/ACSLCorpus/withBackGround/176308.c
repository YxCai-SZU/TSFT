#include <stddef.h>
#include <stdint.h>

/*@ predicate sorted(int *a, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> a[i] <= a[j];
*/

/*@ predicate lower_less(int *a, integer low, integer x) =
      \forall integer k; 0 <= k < low ==> a[k] < x;
*/

/*@ predicate upper_ge(int *a, integer high, integer len, integer x) =
      \forall integer k; high <= k < len ==> x <= a[k];
*/

/*@ lemma bounds_lemma:
      \forall integer low, high, len;
      0 <= low <= high <= len ==> low <= high;
*/

/*@ lemma monotonic_lemma:
      \forall int *a, integer len, integer i, j;
      sorted(a, len) && 0 <= i < j < len ==> a[i] <= a[j];
*/

/*@ requires \valid(a+(0..len-1));
    requires sorted(a, len);
    requires len < 0x80000000;
    requires len >= 0;
    assigns \nothing;
    ensures 0 <= \result <= len;
    ensures \result > 0 ==> a[\result-1] < x;
    ensures \result < len ==> x <= a[\result];
*/
size_t find_insertion_index(int *a, size_t len, int x) {
    size_t low = 0;
    size_t high = len;

    /*@ loop invariant 0 <= low <= high <= len;
        loop invariant low <= high;
        loop invariant lower_less(a, low, x);
        loop invariant upper_ge(a, high, len, x);
        loop invariant sorted(a, len);
        loop invariant len < 0x80000000;
        loop assigns low, high;
        loop variant high - low;
    */
    while (low < high) {
        size_t mid = (low + high) / 2;
        //@ assert low <= mid < high;
        if (a[mid] < x) {
            //@ assert a[mid] < x;
            low = mid + 1;
            //@ assert lower_less(a, low, x);
        } else {
            //@ assert x <= a[mid];
            high = mid;
            //@ assert upper_ge(a, high, len, x);
        }
    }
    return low;
}
