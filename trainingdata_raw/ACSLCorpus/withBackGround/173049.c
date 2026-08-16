#include <stdint.h>

/*@ predicate is_multiple_of_200(integer x) = x % 200 == 0; */

/*@ lemma multiple_case: 
      \forall integer x; 1 <= x <= 100000 ==> 
        (is_multiple_of_200(x) ==> x % 200 == 0); */

/*@ lemma non_multiple_case: 
      \forall integer x; 1 <= x <= 100000 ==> 
        (!is_multiple_of_200(x) ==> x % 200 != 0); */

/*@ requires 1 <= x <= 100000;
    ensures is_multiple_of_200(x) ==> \result == 1;
    ensures !is_multiple_of_200(x) ==> \result == (x / 200 + 1);
    assigns \nothing;
 */
int32_t func(uint32_t x)
{
    int32_t result;
    
    //@ assert 1 <= x <= 100000;
    
    if (x % 200 == 0) {
        //@ assert is_multiple_of_200(x);
        result = 1;
    } else {
        //@ assert !is_multiple_of_200(x);
        result = (int32_t)(x / 200 + 1);
    }
    
    return result;
}
