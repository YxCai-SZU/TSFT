#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds: \forall integer a, b; bounds(a, b) ==> 1 <= product(a, b) <= 10000;
*/

/*@
    requires bounds(a, b);
    ensures \result == (product(a, b) % 2 == 0);
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    bool is_even;
    unsigned int temp;

    //@ assert bounds(a, b);
    
    //@ assert 1 <= product(a, b) <= 10000;

    is_even = false;
    temp = a * b;

    /*@
        loop invariant 0 <= temp <= product(a, b);
        loop invariant temp % 2 == product(a, b) % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp == 0)
    {
        is_even = true;
    }

    //@ assert is_even == (product(a, b) % 2 == 0);
    return is_even;
}
