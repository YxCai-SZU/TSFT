#include <stdint.h>

/*@ predicate is_valid_range(integer a) = 1 <= a && a <= 10; */

/*@ lemma a_squared_bound: 
      \forall integer a; is_valid_range(a) ==> a * a <= 100; */

/*@ lemma a_cubed_bound: 
      \forall integer a; is_valid_range(a) ==> a * a * a <= 1000; */

/*@ logic integer compute_result(integer a) = 
      a + a * a + a * a * a; */

/*@
  requires is_valid_range(a);
  ensures \result == compute_result(a);
  assigns \nothing;
*/
uint32_t func(uint32_t a) {
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t res;

    //@ assert is_valid_range(a);
    
    //@ assert a * a <= 100;
    a1 = a;
    a2 = a * a;
    
    //@ assert a * a * a <= 1000;
    a3 = a * a * a;
    
    res = a1 + a2 + a3;
    //@ assert res == compute_result(a);
    return res;
}
