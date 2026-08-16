#include <limits.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10;
    predicate a_squared_in_range(integer a) = 1 <= a * a <= 100;
    predicate a_cubed_in_range(integer a) = 1 <= a * a * a <= 1000;
    predicate sum_in_range(integer a) = 1 <= a + a * a + a * a * a <= 1110;
    
    logic integer func_result(integer a) = a + a * a + a * a * a;
    
    lemma a_squared_range: \forall integer a; a_in_range(a) ==> a_squared_in_range(a);
    lemma a_cubed_range: \forall integer a; a_in_range(a) ==> a_cubed_in_range(a);
    lemma sum_range: \forall integer a; a_in_range(a) ==> sum_in_range(a);
*/

/*@
    requires 1 <= a <= 10;
    requires a <= 46340;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int func(int a)
{
    int result;
    int a_squared;
    int a_cubed;
    
    //@ assert a_in_range(a);
    
    //@ assert a_squared_in_range(a);
    a_squared = a * a;
    
    //@ assert a_cubed_in_range(a);
    a_cubed = a * a * a;
    
    result = a;
    result += a_squared;
    result += a_cubed;
    
    //@ assert sum_in_range(a);
    //@ assert result == func_result(a);
    
    return result;
}
