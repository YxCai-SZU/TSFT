#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    
    logic integer pow2(integer a) = a * a;
    logic integer pow3(integer a) = a * a * a;
    logic integer expected_result(integer a) = a + pow2(a) + pow3(a);
    
    lemma pow2_bound: \forall integer a; 1 <= a <= 100 ==> pow2(a) <= 10000;
    lemma pow3_bound: \forall integer a; 1 <= a <= 100 ==> pow3(a) <= 1000000;
*/

/*@
    requires a_in_range(a);
    ensures \result == expected_result(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t a_pow_2;
    int64_t a_pow_3;
    int64_t ans;
    
    //@ assert a_in_range(a);
    
    //@ assert pow2(a) <= 10000;
    a_pow_2 = a * a;
    
    //@ assert pow3(a) <= 1000000;
    a_pow_3 = a * a * a;
    
    ans = a + a_pow_2 + a_pow_3;
    
    //@ assert ans == expected_result(a);
    return ans;
}
