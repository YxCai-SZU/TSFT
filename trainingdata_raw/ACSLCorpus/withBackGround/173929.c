/*@
predicate valid_range(integer a) = 1 <= a && a <= 10;

lemma calc_example_1:
    \forall integer a, integer b; valid_range(a) && valid_range(b) ==> a + 1 <= 11;

lemma calc_example_2:
    \forall integer a, integer b; valid_range(a) && valid_range(b) ==> a + b + 1 <= 21;
*/

#include <stdbool.h>

/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    ensures \result == true;
*/
bool verify_calc_example_1(int a, int b) {
    //@ assert 1 <= a;
    //@ assert a <= 10;
    //@ assert a + 1 <= 11;
    return true;
}

/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    ensures \result == true;
*/
bool verify_calc_example_2(int a, int b) {
    //@ assert 1 <= a;
    //@ assert a <= 10;
    //@ assert 1 <= b;
    //@ assert b <= 10;
    //@ assert a + b + 1 <= 21;
    return true;
}

int main() {
    return 0;
}
