#include <stdbool.h>

/*@
    predicate is_within_bounds(integer a, integer b) =
        1 <= a <= 10000 && 1 <= b <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b;
        is_within_bounds(a, b) ==> product(a, b) <= 100000000;

    lemma modulo_preserved: \forall integer c, temp_c;
        temp_c >= 0 && temp_c <= c && (temp_c % 2) == (c % 2) ==>
        (temp_c == 1) ==> (c % 2 != 0);
*/

/*@
    requires is_within_bounds(a, b);
    ensures \result == (product(a, b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int c;
    bool is_odd;
    unsigned int temp_c;

    //@ assert is_within_bounds(a, b);
    //@ assert product(a, b) <= 100000000;

    c = a * b;
    is_odd = false;
    temp_c = c;

    /*@
        loop invariant 0 <= temp_c <= c;
        loop invariant (temp_c % 2) == (c % 2);
        loop invariant is_odd == false;
        loop assigns temp_c, is_odd;
        loop variant temp_c;
    */
    while (temp_c >= 2)
    {
        temp_c -= 2;
    }

    //@ assert (temp_c % 2) == (c % 2);
    
    if (temp_c == 1)
    {
        is_odd = true;
    }

    //@ assert is_odd == (c % 2 != 0);
    return is_odd;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
