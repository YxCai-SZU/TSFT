#include <stdint.h>

/*@ predicate is_mod_zero(integer a, integer b, integer c) =
      c == a % b;
*/

/*@ predicate result_zero_implies_mod_zero(integer a, integer b, integer res) =
      res == 0 ==> a % b == 0;
*/

/*@ predicate result_one_implies_mod_nonzero(integer a, integer b, integer res) =
      res == 1 ==> a % b != 0;
*/

/*@ lemma mod_bounds:
      \forall integer a, b;
      1 <= a <= 100 && 1 <= b <= 100 ==>
      0 <= a % b <= 100;
*/

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> a % b == 0;
    ensures \result == 1 ==> a % b != 0;
    assigns \nothing;
*/
int32_t func(uint64_t a, uint64_t b)
{
    uint64_t c;
    int32_t result;

    c = a % b;
    
    //@ assert is_mod_zero(a, b, c);
    
    if (c == 0)
    {
        result = 0;
    }
    else
    {
        //@ assert c > 0 && c <= 100;
        result = 1;
    }
    
    //@ assert result_zero_implies_mod_zero(a, b, result);
    //@ assert result_one_implies_mod_nonzero(a, b, result);
    
    return result;
}
