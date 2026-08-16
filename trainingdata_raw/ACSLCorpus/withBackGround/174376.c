/*@
predicate is_within_bounds(integer x, integer y) =
    1 <= x && x <= 10 && 1 <= y && y <= 10;

predicate x_le_y(integer x, integer y) =
    0 <= x && x <= y;

lemma product_is_increasing:
    \forall integer x, y; is_within_bounds(x, y) ==> x * y <= 100;

lemma sum_in_range:
    \forall integer x, y; x_le_y(x, y) ==> x + y <= 2 * y;
*/

#include <stdbool.h>

/*@
    requires 1 <= x && x <= 10;
    requires 1 <= y && y <= 10;
    ensures \result == x * y;
    ensures \result <= 100;
*/
int calculate_product(int x, int y) {
    int product;
    //@ assert 1 <= x && x <= 10;
    //@ assert 1 <= y && y <= 10;
    product = x * y;
    //@ assert product <= 100;
    return product;
}

/*@
    requires 0 <= x && x <= y;
    ensures \result == x + y;
    ensures \result <= 2 * y;
*/
int calculate_sum(int x, int y) {
    int sum;
    //@ assert 0 <= x && x <= y;
    sum = x + y;
    //@ assert sum <= 2 * y;
    return sum;
}

int main() {
    return 0;
}
