/*@
    predicate less_than_or_equal(integer a, integer b, integer c) =
        a <= b && b <= c ==> a <= c;

    predicate greater_than_or_equal(integer a, integer b, integer c) =
        a >= b && b >= c ==> a >= c;

    predicate equality(integer a, integer b, integer c) =
        a == b && b == c ==> a == c;

    lemma calc_example_2: \forall integer x; x + 2 <= x + 5;
    lemma calc_example_3: \forall integer x; x + 2 <= x + 5;
    lemma func_less_than: \forall integer a, b, c; less_than_or_equal(a, b, c);
    lemma func_greater_than: \forall integer a, b, c; greater_than_or_equal(a, b, c);
    lemma func_equality: \forall integer a, b, c; equality(a, b, c);
*/

#include <stdbool.h>

/*@
    requires a <= b;
    requires b <= c;
    ensures \result == true;
*/
bool check_less_than_or_equal(int a, int b, int c) {
    //@ assert a <= c;
    return true;
}

/*@
    requires a >= b;
    requires b >= c;
    ensures \result == true;
*/
bool check_greater_than_or_equal(int a, int b, int c) {
    //@ assert a >= c;
    return true;
}

/*@
    requires a == b;
    requires b == c;
    ensures \result == true;
*/
bool check_equality(int a, int b, int c) {
    //@ assert a == c;
    return true;
}

int main() {
    return 0;
}
