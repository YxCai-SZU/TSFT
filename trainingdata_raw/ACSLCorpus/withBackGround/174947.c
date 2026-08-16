#include <stdint.h>

/*@ predicate is_valid_vector(int32_t *v, integer len) =
      len == 3 &&
      1 <= v[0] && v[0] <= 100 &&
      1 <= v[1] && v[1] <= 20 &&
      1 <= v[2] && v[2] <= 2000;
*/

/*@ lemma mul_is_monotonic_increasing:
      \forall integer a, b;
        1 <= a <= 100 && 1 <= b <= 20 ==> a * b <= 2000;
*/

/*@ requires \valid(v+(0..2));
    requires is_valid_vector(v, 3);
    ensures \result >= 0;
    ensures \result <= v[2];
    assigns \nothing;
*/
int32_t func(int32_t *v) {
    int32_t result;
    int32_t temp;
    
    //@ assert 1 <= v[0] && v[0] <= 100;
    //@ assert 1 <= v[1] && v[1] <= 20;
    //@ assert v[0] * v[1] <= 2000;
    
    temp = v[0] * v[1];
    
    if (temp <= v[2]) {
        result = temp;
    } else {
        result = v[2];
    }
    
    //@ assert result >= 0;
    //@ assert result <= v[2];
    
    return result;
}
