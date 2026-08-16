#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    logic integer product_mod_2(integer x, integer y) = (x * y) % 2;

    lemma product_bound: \forall integer x, y; valid_range(x) && valid_range(y) ==> x * y <= 10000;
    lemma mod_2_range: \forall integer v; 0 <= product_mod_2(v, v) < 2;
*/

/*@
    requires valid_range(x) && valid_range(y);
    ensures \result == (product_mod_2(x, y) == 0);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y) {
    // Variable declarations
    unsigned int product;
    int remainder;

    // Precondition assertions
    //@ assert valid_range(x);
    //@ assert valid_range(y);
    //@ assert x * y <= 10000;

    product = x * y;
    remainder = (int)product;

    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant remainder <= (int)product;
        loop invariant remainder >= 0;
        loop invariant remainder == (int)product || remainder % 2 == (int)product % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        //@ assert remainder >= 2;
        remainder -= 2;
        //@ assert remainder >= 0;
    }

    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant remainder < 2;
        loop invariant remainder == (int)product % 2 || remainder == (int)product % 2 - 2;
        loop assigns remainder;
        loop variant 1 - remainder;
    */
    while (remainder < 0) {
        //@ assert remainder < 0;
        remainder += 2;
        //@ assert remainder < 2;
    }

    // Postcondition verification
    //@ assert remainder == (int)product % 2;
    return remainder == 0;
}

int main() {
    return 0;
}
