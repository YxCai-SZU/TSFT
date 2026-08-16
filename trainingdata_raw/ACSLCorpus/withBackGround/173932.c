#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c, integer d) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;

    logic integer twice(integer x) = x * 2;

    predicate condition(integer a, integer b, integer c, integer d) =
        a >= twice(b) || c >= twice(d) || (a + c) >= twice(b + d);
*/

/*@
    requires bounds(a, b, c, d);
    ensures \result == 1 <==> condition(a, b, c, d);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result;
    unsigned int b2;
    unsigned int d2;
    unsigned int bd2;
    unsigned int sum_ac;
    unsigned int sum_bd;

    //@ assert b * 2 <= 200;
    b2 = b * 2;
    //@ assert d * 2 <= 200;
    d2 = d * 2;
    //@ assert (b + d) * 2 <= 400;
    bd2 = (b + d) * 2;
    
    sum_ac = a + c;
    sum_bd = b + d;
    
    result = (a >= b2) || (c >= d2) || (sum_ac >= bd2);
    
    //@ assert result == 1 <==> condition(a, b, c, d);
    return result;
}
