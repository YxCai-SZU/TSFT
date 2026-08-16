#include <stdint.h>

/*@
    predicate is_in_range(integer a) = 1 <= a && a <= 10;

    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer func_result(integer a) = a + square(a) + cube(a);

    lemma square_bounds: \forall integer a; is_in_range(a) ==> 1 <= square(a) <= 100;
    lemma cube_bounds: \forall integer a; is_in_range(a) ==> 1 <= cube(a) <= 1000;
*/

/*@
    requires is_in_range(a);
    ensures \result == func_result(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t a1;
    int64_t a2;
    int64_t a3;
    int64_t ans;

    //@ assert is_in_range(a);
    //@ assert 1 <= a && a <= 10;
    
    //@ assert 1 <= a * a && a * a <= 100;
    a1 = a;
    a2 = a * a;
    
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    a3 = a * a * a;
    
    ans = a1 + a2 + a3;
    //@ assert ans == a + a * a + a * a * a;
    
    return ans;
}
