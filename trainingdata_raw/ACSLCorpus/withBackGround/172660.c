#include <stdint.h>

/*@
    predicate valid_index(integer i) = 0 <= i < 4;

    predicate valid_value(integer v) = 1 <= v <= 10000;

    predicate valid_array(int64_t *arr) =
        \forall integer i; 0 <= i < 4 ==> valid_value(arr[i]);

    logic integer product1(int64_t *arr) = arr[0] * arr[1];

    logic integer product2(int64_t *arr) = arr[2] * arr[3];

    logic integer max_product(int64_t *arr) =
        product1(arr) > product2(arr) ? product1(arr) : product2(arr);

    lemma product_bound1:
        \forall int64_t *arr; valid_array(arr) ==> product1(arr) <= 100000000;

    lemma product_bound2:
        \forall int64_t *arr; valid_array(arr) ==> product2(arr) <= 100000000;

    lemma product_positive1:
        \forall int64_t *arr; valid_array(arr) ==> product1(arr) > 0;

    lemma product_positive2:
        \forall int64_t *arr; valid_array(arr) ==> product2(arr) > 0;
*/

/*@
    requires \valid_read(arr + (0..3));
    requires 1 <= arr[0] <= 10000;
    requires 1 <= arr[1] <= 10000;
    requires 1 <= arr[2] <= 10000;
    requires 1 <= arr[3] <= 10000;
    ensures \result == arr[0] * arr[1] || \result == arr[2] * arr[3];
    ensures \result >= 1;
*/
int64_t func(const int64_t *arr)
{
    // Declare all variables at the top
    int64_t max_val;
    int64_t prod1;
    int64_t prod2;

    //@ assert valid_array(arr);
    //@ assert product1(arr) <= 100000000;
    //@ assert product2(arr) <= 100000000;
    //@ assert product1(arr) > 0 || product2(arr) > 0;

    prod1 = arr[0] * arr[1];
    prod2 = arr[2] * arr[3];

    //@ assert prod1 == product1(arr);
    //@ assert prod2 == product2(arr);

    if (prod1 > prod2) {
        max_val = prod1;
    } else {
        max_val = prod2;
    }

    //@ assert max_val == max_product(arr);
    //@ assert max_val >= 1;

    return max_val;
}
