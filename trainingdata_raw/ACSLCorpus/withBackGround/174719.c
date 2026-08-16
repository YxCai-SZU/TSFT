#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 5000 &&
        1 <= b && b <= 5000 &&
        1 <= c && c <= 100000;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_bounds: \forall integer a, b;
        valid_input(a, b, 0) ==> 2 <= sum(a, b) && sum(a, b) <= 10000;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result == true <==> c <= a + b;
    ensures \result == false <==> c > a + b;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    if (c <= a + b)
    {
        //@ assert c <= a + b;
        result = true;
    }
    else
    {
        //@ assert c > a + b;
        result = false;
    }

    return result;
}
