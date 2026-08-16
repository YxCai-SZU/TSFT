#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c) =
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100;

    logic integer mul1(integer a, integer b, integer c) = (a * b) * c;
    logic integer mul2(integer a, integer b, integer c) = a * (b * c);

    lemma mul_assoc_proof:
        \forall integer a, b, c;
            bounds(a, b, c) ==> mul1(a, b, c) == mul2(a, b, c);
*/

/*@
    requires 0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100;
    ensures \result == true <==> (a * b) * c == a * (b * c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert a <= 100 && b <= 100 && c <= 100;
    //@ assert a * b <= 10000;
    //@ assert (a * b) * c <= 1000000;
    //@ assert b * c <= 10000;
    //@ assert a * (b * c) <= 1000000;
    //@ assert a * (b * c) == (a * b) * c;

    result = ((a * b) * c) == (a * (b * c));
    return result;
}
