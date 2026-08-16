#include <stdint.h>

/*@
    predicate multiplication_in_bounds(unsigned a, unsigned b) =
        a <= 4294967295 && b <= 4294967295 && (unsigned long long)a * b <= 4294967295;

    logic integer multiply(unsigned a, unsigned b) = a * b;

    lemma multiplication_stays_in_bounds:
        \forall unsigned a, b; multiplication_in_bounds(a, b) ==> (unsigned)multiply(a, b) == a * b;
*/

/*@
    requires multiplication_in_bounds(a, b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
unsigned func(unsigned a, unsigned b)
{
    //@ assert multiplication_in_bounds(a, b);
    unsigned res = a * b;
    //@ assert res == multiply(a, b);
    return res;
}

/*@
    requires multiplication_in_bounds(a, b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
unsigned func2(unsigned a, unsigned b)
{
    //@ assert multiplication_in_bounds(a, b);
    unsigned res = a * b;
    //@ assert res == multiply(a, b);
    return res;
}

/*@
    requires multiplication_in_bounds(a, b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
unsigned func3(unsigned a, unsigned b)
{
    //@ assert multiplication_in_bounds(a, b);
    unsigned res = a * b;
    //@ assert res == multiply(a, b);
    return res;
}
