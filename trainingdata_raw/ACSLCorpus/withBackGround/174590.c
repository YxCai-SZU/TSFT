/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_safe_sum(integer a, integer b) = a + b <= 2147483647;
    predicate is_safe_product(integer a, integer b) = a * b <= 2147483647;
*/

/*@
    logic integer max_spec(integer a, integer b) = (a > b) ? a : b;
    logic integer abs_spec(integer x) = (x < 0) ? -x : x;
    logic integer perimeter_rectangle(integer width, integer height) = 2 * (width + height);
    logic integer area_rectangle(integer width, integer height) = width * height;
*/

/*@
    lemma max_spec_1_2: max_spec(1, 2) == 2;
    lemma max_spec_neg1_1: max_spec(-1, 1) == 1;
    lemma abs_spec_neg1: abs_spec(-1) == 1;
    lemma abs_spec_1: abs_spec(1) == 1;
    lemma abs_spec_0: abs_spec(0) == 0;
*/

#include <limits.h>

int main() {
    int a, b, x, width, height, perimeter, area;
    
    //@ assert max_spec(1, 2) == 2;
    //@ assert max_spec(-1, 1) == 1;
    //@ assert abs_spec(-1) == 1;
    //@ assert abs_spec(1) == 1;
    //@ assert abs_spec(0) == 0;
    
    return 0;
}
