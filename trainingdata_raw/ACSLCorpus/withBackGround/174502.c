#include <stdbool.h>

/*@
    predicate is_positive(integer x) = x > 0;
    predicate double_le_quad(integer x) = x * 2 <= x * 4;
    predicate abs_less_than(integer x) = x - 5 < x;
*/

/*@
    lemma calc_example_3: \forall integer x; is_positive(x) ==> double_le_quad(x);
    lemma example_abs_less_than: \forall integer x; is_positive(x) ==> abs_less_than(x);
*/

/*@
    requires is_positive(x);
    ensures double_le_quad(x);
*/
void calc_example_3(int x) {
    //@ assert x * 2 <= x * 3;
    //@ assert x * 3 <= x * 4;
}

/*@
    requires is_positive(x);
    ensures abs_less_than(x);
*/
void example_abs_less_than(int x) {
    //@ assert x - 5 < x;
}

int main() {
    return 0;
}
