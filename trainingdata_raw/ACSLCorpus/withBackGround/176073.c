#include <stdbool.h>

/*@
    predicate is_even_mod(integer product) =
        product % 2 == 0;

    lemma product_bounds:
        \forall integer a, b;
        1 <= a <= 10000 && 1 <= b <= 10000 ==>
        1 <= a * b <= 10000 * 10000;
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int product;
    bool is_even;
    unsigned int temp;

    product = a * b;
    is_even = true;
    temp = product;

    //@ assert 1 <= a * b <= 10000 * 10000;

    /*@
        loop invariant 0 <= temp <= a * b;
        loop invariant temp <= product;
        loop invariant temp % 2 == product % 2;
        loop invariant 1 <= a <= 10000;
        loop invariant 1 <= b <= 10000;
        loop invariant 1 <= a * b <= 10000 * 10000;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp == 1)
    {
        is_even = false;
    }

    //@ assert is_even == (product % 2 == 0);
    return is_even;
}
