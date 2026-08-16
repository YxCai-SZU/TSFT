#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == ((((a) * (b)) % 2) != 0);
    assigns \nothing;
*/
bool func(int a, int b) {
    int a_abs;
    int b_abs;
    int product;
    bool is_odd;
    int abs_product;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    a_abs = (a < 0) ? -a : a;
    b_abs = (b < 0) ? -b : b;

    //@ assert 1 <= a_abs <= 10000 && 1 <= b_abs <= 10000;
    //@ assert 0 <= a_abs * b_abs <= 100000000;
    product = a_abs * b_abs;

    is_odd = false;
    abs_product = product;

    /*@
        loop invariant 0 <= abs_product <= 100000000;
        loop invariant abs_product <= product;
        loop invariant (abs_product % 2 == 0) == (product % 2 == 0);
        loop invariant (product % 2 == 0) ==> !is_odd;
        loop assigns abs_product, is_odd;
        loop variant abs_product;
    */
    while (abs_product > 0) {
        if (abs_product == 1) {
            is_odd = true;
            break;
        }

        //@ assert 0 <= abs_product * abs_product <= 10000000000000000;
        abs_product -= 2;
    }

    //@ assert is_odd == (product % 2 != 0);
    return is_odd;
}
