#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10;
    
    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer total(integer a) = a + square(a) + cube(a);
    
    lemma square_bound: \forall integer a; a_in_range(a) ==> square(a) <= 100;
    lemma cube_bound: \forall integer a; a_in_range(a) ==> cube(a) <= 1000;
    lemma total_bound: \forall integer a; a_in_range(a) ==> total(a) <= 1110;
*/

/*@
    requires a_in_range(a);
    ensures \result == total(a);
    assigns \nothing;
*/
int32_t func(int32_t a) {
    // Variable declarations at scope top
    int32_t a2;
    int32_t a3;
    int32_t ans;
    
    //@ assert a_in_range(a);
    //@ assert square(a) <= 100;
    //@ assert cube(a) <= 1000;
    //@ assert total(a) <= 1110;
    
    a2 = a * a;
    a3 = a * a * a;
    ans = a + a2 + a3;
    
    //@ assert ans == total(a);
    return ans;
}
