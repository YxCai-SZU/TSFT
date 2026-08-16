#include <stdbool.h>

/*@
    predicate is_sum_possible(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;
*/

/*@
    lemma sum_bound_ab:
        \forall integer a, b;
            0 <= a <= 100 && 0 <= b <= 100 ==> a + b <= 200;
    lemma sum_bound_ac:
        \forall integer a, c;
            0 <= a <= 100 && 0 <= c <= 100 ==> a + c <= 200;
    lemma sum_bound_bc:
        \forall integer b, c;
            0 <= b <= 100 && 0 <= c <= 100 ==> b + c <= 200;
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result <==> is_sum_possible(a, b, c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    int state = 0;
    
    //@ assert a + b <= 200;
    if (a + b == c)
    {
        state += 1;
    }
    
    //@ assert a + c <= 200;
    if (a + c == b)
    {
        state += 1;
    }
    
    //@ assert b + c <= 200;
    if (b + c == a)
    {
        state += 1;
    }
    
    //@ assert state > 0 <==> is_sum_possible(a, b, c);
    return state > 0;
}
