#include <limits.h>

/*@
    predicate positive_and_bounded(integer x) =
        x > 0 && x <= 10;
*/

/*@
    lemma nonlinear_arithmetic_example_6:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            x * (y + z) == x * y + x * z;
*/

/*@
    lemma nonlinear_arithmetic_example_7:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            (x * y) * z == x * (y * z);
*/

/*@
    lemma nonlinear_arithmetic_example_8:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            x * (y * z) == (x * y) * z;
*/

/*@
    lemma nonlinear_arithmetic_example_9:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            x * (y + z) <= x * y + x * z;
*/

/*@
    lemma nonlinear_arithmetic_example_10:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            (x * y) * z <= x * (y * z);
*/

/*@
    lemma nonlinear_arithmetic_example_11:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            x * (y * z) <= (x * y) * z;
*/

/*@
    lemma nonlinear_arithmetic_example_12:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            x * (y + z) == x * y + x * z;
*/

/*@
    lemma nonlinear_arithmetic_example_13:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            (x * y) * z == x * (y * z);
*/

/*@
    lemma nonlinear_arithmetic_example_14:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            x * (y * z) == (x * y) * z;
*/

/*@
    lemma nonlinear_arithmetic_example_15:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            x * (y + z) <= x * y + x * z;
*/

/*@
    lemma nonlinear_arithmetic_example_16:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            (x * y) * z <= x * (y * z);
*/

/*@
    lemma nonlinear_arithmetic_example_17:
        \forall integer x, y, z;
            positive_and_bounded(x) &&
            positive_and_bounded(y) &&
            positive_and_bounded(z) ==>
            x * (y * z) <= (x * y) * z;
*/

int main() {
    return 0;
}
