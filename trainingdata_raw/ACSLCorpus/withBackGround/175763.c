#include <stdbool.h>
/*@
    predicate valid_index(long *arr, integer i) =
        \valid(arr + i);

    predicate array_bounds(long *arr, integer len) =
        len >= 4 &&
        \valid(arr + (0..len-1)) &&
        arr[0] >= 1 && arr[0] <= 10000 &&
        arr[1] >= 1 && arr[1] <= 10000 &&
        arr[2] >= 1 && arr[2] <= 10000 &&
        arr[3] >= 1 && arr[3] <= 10000;

    logic integer product1(long *arr) = arr[0] * arr[1];
    logic integer product2(long *arr) = arr[2] * arr[3];

    lemma product1_bounds:
        \forall long *arr; array_bounds(arr, 4) ==>
            product1(arr) >= 1 && product1(arr) <= 100000000;

    lemma product2_bounds:
        \forall long *arr; array_bounds(arr, 4) ==>
            product2(arr) >= 1 && product2(arr) <= 100000000;
*/

/*@
    requires array_bounds(x, len);
    ensures \result == product1(x) || \result == product2(x);
    ensures \result >= 1;
*/
long func(long *x, int len) {
    long product1;
    long product2;
    long result;

    //@ assert 0 < len;
    product1 = x[0] * x[1];

    //@ assert 2 < len;
    product2 = x[2] * x[3];

    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }
    //@ assert result >= 1;
    return result;
}
