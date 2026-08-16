#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 500 &&
        1 <= b && b <= 500 &&
        1 <= c && c <= 1000;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_bounds:
        \forall integer a, b;
        valid_input(a, b, 0) ==> 2 <= sum(a, b) && sum(a, b) <= 1000;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result == true <==> c <= a + b;
    ensures \result == false <==> c > a + b;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long ab;

    //@ assert valid_input(a, b, c);
    ab = a + b;

    if (c <= ab)
    {
        //@ assert c <= a + b;
        return true;
    }
    else
    {
        //@ assert !(c <= a + b);
        return false;
    }
}
