#include <stdbool.h>
#include <stdint.h>

/* ACSL predicates and lemmas from the first snippet */
/*@
    predicate is_odd(integer x) = x == 1 || x == 3 || x == 5;
    predicate is_even(integer x) = x == 2 || x == 4;
    logic integer multiply(integer a, integer b) = a * b;
    
    lemma multiplication_bound: \forall integer a, b; 1 <= a <= 5 && 1 <= b <= 5 ==> a * b <= 25;
*/

/*@
    predicate msb_set(unsigned int a) = (a & 0x80) == 0x80;
*/

/*@ predicate is_valid_array(int *a) =
      \valid(a) && \valid(a+1) &&
      1 <= a[0] && a[0] <= 100 &&
      0 <= a[1] && a[1] <= 4111;
*/

/*@ lemma bound_lemma_1:
      \forall integer a0; 1 <= a0 && a0 <= 100 ==> 100 * (10 - a0) <= 100 * 10;
*/

/*@ lemma bound_lemma_2:
      \forall integer a0, integer a1;
        1 <= a0 && a0 <= 100 && 0 <= a1 && a1 <= 4111 ==>
        a1 + 100 * (10 - a0) <= 4111 + 100 * 10;
*/

/* First underlying function: conditional multiplier */
unsigned int func_mult(unsigned int a, unsigned int b)
{
    unsigned int res;
    
    if ((a == 1 || a == 3 || a == 5) || (b == 2 || b == 4)) {
        res = 0;
    } else {
        //@ assert a * b <= 25;
        res = a * b;
    }
    
    //@ assert (is_odd(a) || is_even(b)) ==> res == 0;
    //@ assert (!is_odd(a) && !is_even(b)) ==> res == multiply(a, b);
    
    return res;
}

/* Second underlying function: check MSB */
bool func_msb(unsigned int a)
{
    unsigned int msb;
    bool result;
    
    msb = a & 0x80;
    //@ assert msb == (a & 0x80);
    
    result = (msb == 0x80);
    return result;
}

/* Third underlying function: compute adjusted value */
int func_adjust(int *a)
{
    int result;
    int a0_val;
    int a1_val;
    
    //@ assert \valid(a) && \valid(a+1);
    a0_val = a[0];
    a1_val = a[1];
    
    //@ assert 1 <= a0_val && a0_val <= 100;
    //@ assert 0 <= a1_val && a1_val <= 4111;
    
    if (a0_val >= 10)
    {
        result = a1_val;
        //@ assert result == a1_val;
    }
    else
    {
        int temp;
        //@ assert a0_val < 10;
        //@ assert 100 * (10 - a0_val) <= 100 * 10;
        temp = 100 * (10 - a0_val);
        //@ assert a1_val + temp <= 4111 + 100 * 10;
        result = a1_val + temp;
        //@ assert result == a1_val + (100 * (10 - a0_val));
    }
    
    return result;
}

/* Synthesized function: config-based data processing
 * Scenario: A configuration parser processes a config array [key, value] and
 * a multiplier pair (a,b). It adjusts the value based on the key, then applies
 * a multiplier if the MSB of the adjusted value is not set.
 * Control flow: sequence (func_adjust -> func_msb -> func_mult)
 */
unsigned int process_config(int *config, unsigned int a, unsigned int b)
{
    int adjusted;
    bool msb_flag;
    unsigned int final_result;
    
    adjusted = func_adjust(config);
    
    msb_flag = func_msb((unsigned int)adjusted);
    
    if (msb_flag) {
        final_result = 0;
    } else {
        final_result = func_mult(a, b);
    }
    
    //@ assert final_result <= 4111 + 100 * 10;
    
    return final_result;
}
