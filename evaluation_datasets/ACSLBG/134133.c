/*@
    logic integer func(integer a, integer b, integer c) =
        (a >= b && a >= c) ? a :
        (b >= a && b >= c) ? b :
        c;

    lemma max_no_less_than:
        \forall integer a, b, c;
            a <= func(a, b, c) &&
            b <= func(a, b, c) &&
            c <= func(a, b, c);
*/

#include <stdbool.h>


void test(void) {
    //@ assert 10 <= func(10, 20, 30);
    //@ assert 20 <= func(10, 20, 30);
    //@ assert 30 <= func(10, 20, 30);
}

int main(void) {
    test();
    return 0;
}
