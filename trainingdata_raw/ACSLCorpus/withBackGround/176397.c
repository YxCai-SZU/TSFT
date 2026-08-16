#include <stdint.h>

/*@
    predicate is_valid_range(integer a) = 1 <= a && a <= 10;
    
    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer expected_result(integer a) = a + square(a) + cube(a);
    
    lemma square_bounds:
        \forall integer a; is_valid_range(a) ==> 1 <= square(a) <= 100;
    
    lemma cube_bounds:
        \forall integer a; is_valid_range(a) ==> 1 <= cube(a) <= 1000;
*/

/*@
    requires is_valid_range(a);
    ensures \result == expected_result(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t a_2;
    int64_t a_3;
    int64_t ans;
    
    //@ assert is_valid_range(a);
    
    //@ assert 1 <= a * a && a * a <= 100;
    a_2 = a * a;
    
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    a_3 = a * a * a;
    
    ans = a + a_2 + a_3;
    
    //@ assert ans == a + square(a) + cube(a);
    return ans;
}
