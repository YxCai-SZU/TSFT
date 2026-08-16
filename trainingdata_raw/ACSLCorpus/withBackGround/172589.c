#include <stdbool.h>

/*@
    predicate pos(integer x) = x > 0;

    lemma non_linear_arith_example3:
        \forall integer a, b, c;
            pos(a) && pos(b) && pos(c) ==>
            a * b * c <= a * (b + 1) * c;
*/

int main() {
    int a, b, c;
    a = 1;
    b = 1;
    c = 1;

    //@ assert pos(a) && pos(b) && pos(c);
    //@ assert a * b * c <= a * (b + 1) * c;

    return 0;
}
