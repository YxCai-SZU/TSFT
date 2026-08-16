#include <stdbool.h>

/*@
    predicate valid_index(int* arr, integer i) =
        0 <= i && i < 4;

    predicate valid_array(int* arr) =
        \valid(arr + (0..3)) &&
        1 <= arr[0] <= 10000 &&
        1 <= arr[1] <= 10000 &&
        1 <= arr[2] <= 10000 &&
        1 <= arr[3] <= 10000;

    logic integer product1(int* arr) = arr[0] * arr[1];
    logic integer product2(int* arr) = arr[2] * arr[3];

    lemma product1_bounds: \forall int* arr; valid_array(arr) ==> 1 <= product1(arr) <= 100000000;
    lemma product2_bounds: \forall int* arr; valid_array(arr) ==> 1 <= product2(arr) <= 100000000;
*/

/*@
    requires valid_array(x);
    ensures \result == product1(x) || \result == product2(x);
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int* x) {
    int product1;
    int product2;
    int result;

    //@ assert 1 <= x[0] <= 10000;
    //@ assert 1 <= x[1] <= 10000;
    //@ assert 1 <= x[2] <= 10000;
    //@ assert 1 <= x[3] <= 10000;

    //@ assert x[0] * x[1] <= 10000 * 10000;
    product1 = x[0] * x[1];

    //@ assert x[2] * x[3] <= 10000 * 10000;
    product2 = x[2] * x[3];

    //@ assert product1 >= 1;
    //@ assert product2 >= 1;

    if (product1 > product2) {
        //@ assert product1 == product1(x) || product1 == product2(x);
        result = product1;
    } else {
        //@ assert product2 == product1(x) || product2 == product2(x);
        result = product2;
    }

    return result;
}
