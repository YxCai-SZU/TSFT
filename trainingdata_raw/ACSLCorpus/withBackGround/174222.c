#include <stdint.h>

/*@ predicate input_in_range(integer i) = 1 <= i && i <= 100; */

/*@ lemma square_bound: 
      \forall integer i; input_in_range(i) ==> i * i <= 10000; */

/*@ lemma triple_square_bound: 
      \forall integer i; input_in_range(i) ==> i * i * 3 <= 30000; */

/*@ requires input_in_range(input);
    ensures \result == input * input * 3;
    assigns \nothing;
 */
int32_t func(int32_t input)
{
    //@ assert input_in_range(input);
    //@ assert input * input <= 10000;
    //@ assert input * input * 3 <= 30000;
    return input * input * 3;
}
