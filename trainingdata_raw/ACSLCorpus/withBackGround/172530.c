#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    
    logic integer multiply_8(integer a) = a * 8;
    
    lemma multiplication_bound: 
        \forall integer a; a_in_range(a) ==> 8 <= multiply_8(a) <= 800;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == (a * 8 / 100 <= b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int a1;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    
    a1 = a * 8;
    
    //@ assert a1 == a * 8;
    //@ assert 8 <= a1 <= 800;
    
    return a1 / 100 <= b;
}
