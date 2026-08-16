#include <limits.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10;
    
    logic integer final_result(integer a) = a + a * a + a * a * a;
    
    lemma no_overflow_mul1: \forall integer a; a_in_range(a) ==> a * a <= 100;
    lemma no_overflow_mul2: \forall integer a; a_in_range(a) ==> a * a * a <= 1000;
    lemma no_overflow_add1: \forall integer a; a_in_range(a) ==> a + a * a <= 110;
    lemma no_overflow_total: \forall integer a; a_in_range(a) ==> a + a * a + a * a * a <= 1110;
*/

/*@
    requires 1 <= a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int func(int a)
{
    int result;
    
    //@ assert a >= 1 && a <= 10;
    
    //@ assert a * a <= 100;
    
    //@ assert a * a * a <= 1000;
    
    //@ assert a + a * a <= 110;
    
    //@ assert a + a * a + a * a * a <= 1110;
    
    result = a + a * a + a * a * a;
    
    return result;
}
