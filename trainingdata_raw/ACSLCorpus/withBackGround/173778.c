#include <stdbool.h>
/*@
    predicate valid_range(integer n) = 2 <= n <= 100;
    predicate valid_array(int *arr, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 100;
    predicate all_less_equal(int *a, int *b, integer n) =
        \forall integer i; 0 <= i < n ==> a[i] <= b[i];
    predicate loop_invariant(int *a, int *b, integer n, integer i) =
        0 <= i <= n &&
        valid_range(n) &&
        valid_array(a, n) &&
        valid_array(b, n) &&
        (\forall integer j; 0 <= j < i ==> a[j] <= b[j]);
*/

/*@
    requires valid_range(n);
    requires \valid(a + (0 .. n-1));
    requires \valid(b + (0 .. n-1));
    requires valid_array(a, n);
    requires valid_array(b, n);
    ensures \result == true <==> all_less_equal(a, b, n);
*/
bool func(int n, int *a, int *b) {
    int i = 0;
    /*@
        loop invariant loop_invariant(a, b, n, i);
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] > b[i]) {
            return false;
        }
        i++;
    }
    return true;
}
