#include <stdbool.h>

/*@
    predicate less_than_100(integer x) = x < 100;
    predicate less_than_101(integer x) = x < 101;
    predicate less_than_110(integer x) = x < 110;
    predicate x_plus_one_lt_x_plus_ten(integer x) = x + 1 < x + 10;
*/

/*@
    lemma simple_calc_chain: \forall integer x; less_than_100(x) ==> x_plus_one_lt_x_plus_ten(x);
    lemma intermediate_steps: \forall integer x; less_than_100(x) ==> x_plus_one_lt_x_plus_ten(x);
    lemma multiple_intermediate_steps: \forall integer x; less_than_100(x) ==> x_plus_one_lt_x_plus_ten(x);
    lemma equivalent_intermediate_steps: \forall integer x; less_than_100(x) ==> x_plus_one_lt_x_plus_ten(x);
*/

void main() {
    // No implementation needed for proof lemmas
}
