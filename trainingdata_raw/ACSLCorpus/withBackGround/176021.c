#include <stdbool.h>
#include <stdint.h>

/*@
    predicate pos_params(unsigned a, unsigned b, unsigned c) =
        a > 0 && b > 0 && c > 0 && a * b * c <= 0xffffffff;

    lemma product_bound_ab:
        \forall unsigned a, b, c;
            pos_params(a, b, c) ==> a * b <= 0xffffffff;

    lemma product_bound_bc:
        \forall unsigned a, b, c;
            pos_params(a, b, c) ==> b * c <= 0xffffffff;
*/

/*@
    requires pos_params(a, b, c);
    ensures \result == (a * b <= b * c);
    assigns \nothing;
*/
bool func(unsigned a, unsigned b, unsigned c)
{
    unsigned product_ab;
    unsigned product_bc;
    bool result;

    //@ assert a * b <= 0xffffffff;
    //@ assert b * c <= 0xffffffff;

    product_ab = a * b;
    product_bc = b * c;

    result = product_ab <= product_bc;
    return result;
}

int main()
{
    return 0;
}
