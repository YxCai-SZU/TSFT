#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10;

    logic integer expr_value(integer a) = a + a * a + a * a * a;

    lemma bounds_lemma:
        \forall integer a; a_in_range(a) ==> 
            1 <= a * a * a <= 1000 &&
            2 <= a + a * a <= 1100 &&
            3 <= expr_value(a) <= 2100;
*/

/*@
    requires a_in_range(a);
    ensures \result == expr_value(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t res;
    
    //@ assert a_in_range(a);
    
    //@ assert 1 <= a * a * a <= 1000;
    
    //@ assert 2 <= a + a * a <= 1100;
    
    //@ assert 3 <= a + a * a + a * a * a <= 2100;
    
    res = a + a * a + a * a * a;
    
    //@ assert res == expr_value(a);
    
    return res;
}
