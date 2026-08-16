#include <stdbool.h>

/*@
    predicate valid_input(int* a, integer len) =
        len == 2 &&
        1 <= a[0] && a[0] <= 20 &&
        1 <= a[1] && a[1] <= 20;

    logic integer sum_val(integer x, integer y) = x + y;
    logic integer diff_val(integer x, integer y) = x - y;
    logic integer prod_val(integer x, integer y) = x * y;

    lemma product_bound: \forall integer x, y; 1 <= x <= 20 && 1 <= y <= 20 ==> x * y <= 400;
*/

/*@
    requires \valid(a+(0..1));
    requires valid_input(a, 2);
    ensures \result == sum_val(a[0], a[1]) ||
            \result == prod_val(a[0], a[1]) ||
            \result == diff_val(a[0], a[1]);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int* a) {
    int x;
    int y;
    int sum;
    int diff;
    int prod;
    int max_val;

    x = a[0];
    y = a[1];
    //@ assert 1 <= x <= 20;
    //@ assert 1 <= y <= 20;
    sum = x + y;
    diff = x - y;
    //@ assert product_bound: x * y <= 400;
    prod = x * y;

    if (sum > diff) {
        if (sum > prod) {
            max_val = sum;
        } else {
            max_val = prod;
        }
    } else {
        if (diff > prod) {
            max_val = diff;
        } else {
            max_val = prod;
        }
    }

    //@ assert max_val == sum || max_val == prod || max_val == diff;
    //@ assert max_val >= 0;
    return max_val;
}
