#include <limits.h>

/*@
    predicate negative(integer x) = x < 0;
    predicate positive(integer x) = x > 0;
    predicate less_than_five(integer x) = x < 5;
    predicate greater_than_five(integer x) = x > 5;
    predicate less_than_negative_five(integer x) = x < -5;
    predicate greater_than_negative_five(integer x) = x > -5;
*/

/*@
    lemma proof_example_negative: \forall integer x; negative(x) ==> x <= -1;
    lemma proof_example_positive: \forall integer x; positive(x) ==> x >= 1;
    lemma proof_example_threshold: \forall integer x; less_than_five(x) ==> x < 5;
    lemma proof_example_threshold_strict: \forall integer x; greater_than_five(x) ==> x > 5;
    lemma proof_example_threshold_strict_negative: \forall integer x; less_than_negative_five(x) ==> x < -5;
    lemma proof_example_threshold_strict_negative_strict: \forall integer x; greater_than_negative_five(x) ==> x > -5;
*/

int main() {
    return 0;
}
