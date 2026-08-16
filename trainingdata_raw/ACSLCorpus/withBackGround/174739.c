#include <stdbool.h>

/*@
    predicate greater_than_or_equal_chain(integer a, integer b, integer c) =
        a >= b && b >= c;
*/

/*@
    lemma calc_example_10:
        \forall integer a, b; a + b == b + a ==> a + b == b + a;
*/

/*@
    lemma check_greater_than_or_equal:
        \forall integer a, b, c; greater_than_or_equal_chain(a, b, c) ==>
            greater_than_or_equal_chain(a, b, c);
*/

/*@
    lemma check_greater_than_or_equal_chain:
        \forall integer a, b, c; greater_than_or_equal_chain(a, b, c) ==>
            greater_than_or_equal_chain(a, b, c);
*/

/*@
    lemma check_greater_than_or_equal_chain_with_calc:
        \forall integer a, b; a >= b ==> a >= b;
*/

/*@
    lemma check_greater_than_or_equal_chain_with_calculation:
        \forall integer a, b, c; greater_than_or_equal_chain(a, b, c) ==>
            greater_than_or_equal_chain(a, b, c);
*/

int main() {
    return 0;
}
