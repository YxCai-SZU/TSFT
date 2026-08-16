#include <stdint.h>

/*@ predicate is_valid_pair(integer a, integer b) =
      1 <= a && a <= 3 &&
      1 <= b && b <= 3 &&
      a != b;
*/

/*@ lemma result_one_cases:
      \forall integer a, b;
      is_valid_pair(a, b) ==>
      (a == 2 && b == 1) || (a == 1 && b == 3) || (a == 3 && b == 2) ==>
      \let r = 1; r == 1;
*/

/*@ lemma result_minus_one_cases:
      \forall integer a, b;
      is_valid_pair(a, b) ==>
      (a == 1 && b == 2) || (a == 2 && b == 3) || (a == 3 && b == 1) ==>
      \let r = -1; r == -1;
*/

/*@
  requires is_valid_pair(a, b);
  ensures \result == 1 || \result == -1;
  ensures \result == 1 ==> (a == 2 && b == 1) || (a == 1 && b == 3) || (a == 3 && b == 2);
  ensures \result == -1 ==> (a == 1 && b == 2) || (a == 2 && b == 3) || (a == 3 && b == 1);
  assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    int32_t a_val;
    int32_t b_val;
    int32_t result;

    //@ assert is_valid_pair(a, b);
    
    if (a == 1) {
        a_val = 1;
    } else if (a == 2) {
        a_val = 2;
    } else {
        a_val = 3;
    }
    
    if (b == 1) {
        b_val = 1;
    } else if (b == 2) {
        b_val = 2;
    } else {
        b_val = 3;
    }
    
    //@ assert a_val == (int32_t)a;
    //@ assert b_val == (int32_t)b;
    
    if (a_val == 2) {
        if (b_val == 1) {
            //@ assert a == 2 && b == 1;
            result = 1;
        } else {
            //@ assert a == 2 && b == 3;
            result = -1;
        }
    } else if (a_val == 1) {
        if (b_val == 3) {
            //@ assert a == 1 && b == 3;
            result = 1;
        } else {
            //@ assert a == 1 && b == 2;
            result = -1;
        }
    } else {
        if (b_val == 1) {
            //@ assert a == 3 && b == 1;
            result = -1;
        } else {
            //@ assert a == 3 && b == 2;
            result = 1;
        }
    }
    
    //@ assert result == 1 || result == -1;
    return result;
}
