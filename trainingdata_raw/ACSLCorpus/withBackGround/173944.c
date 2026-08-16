#include <stdbool.h>

/*@ predicate is_valid_params(integer k, integer x) =
      1 <= k <= 100 && 1 <= x <= 100000;
*/

/*@ logic integer scaled_k(integer i) = 500 * i; */

/*@ lemma loop_invariant_maintained:
      \forall integer i, integer k, integer k_conv;
      0 <= i <= k && 1 <= k <= 100 && k_conv == scaled_k(i) ==>
      i + 1 <= k ==> k_conv + 500 == scaled_k(i + 1);
*/

/*@ lemma final_scaling:
      \forall integer k, integer k_conv;
      1 <= k <= 100 && k_conv == scaled_k(k) ==>
      k_conv == 500 * k;
*/

/*@ requires is_valid_params(k, x);
    ensures \result == (500 * k >= x);
*/
bool func(long k, long x)
{
    long k_converted = 0;
    long i = 0;
    
    /*@ loop invariant 0 <= i <= k;
        loop invariant k_converted == scaled_k(i);
        loop assigns k_converted, i;
    */
    while (i < k) {
        k_converted += 500;
        i += 1;
        //@ assert k_converted == scaled_k(i);
    }
    
    //@ assert k_converted == scaled_k(k);
    //@ assert k_converted == 500 * k;
    
    return k_converted >= x;
}
