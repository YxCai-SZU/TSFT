#include <stddef.h>

/* First function: compute adjusted value based on k */
/*@
    predicate valid_k(integer k) = 1 <= k <= 23;

    logic integer func_spec(integer k) = 48 - k;

    lemma func_lemma:
        \forall integer k; valid_k(k) ==> func_spec(k) >= 0;
*/

int func(size_t k) {
    int x;
    //@ assert valid_k(k);
    x = 48 - (int)k;
    
    if (x < 0) {
        //@ assert x == 48 - (int)k;
        //@ assert x < 0;
        //@ assert x + 24 == 48 - (int)k;
        return x + 24;
    } else {
        //@ assert x == 48 - (int)k;
        //@ assert x >= 0;
        return x;
    }
}

/* Second function: compute triangle number */
/*@
    predicate is_valid_n(integer n) = 2 <= n && n <= 100;
    
    logic integer triangle_number(integer n) = (n * (n - 1)) / 2;
    
    lemma product_bounds: \forall integer n; is_valid_n(n) ==> n * (n - 1) <= 9900;
    lemma result_bounds: \forall integer n; is_valid_n(n) ==> triangle_number(n) <= 4950;
*/

unsigned long func2(unsigned long n) {
    unsigned long result;
    
    //@ assert n >= 2 && n <= 100;
    //@ assert n - 1 >= 1 && n - 1 <= 99;
    //@ assert n * (n - 1) <= 9900;
    //@ assert (n * (n - 1)) / 2 <= 4950;
    
    result = (n * (n - 1)) / 2;
    return result;
}

/* Synthesized function: simulate a packet buffer adjustment in a network protocol
 * Scenario: In a network protocol handler, we have a buffer capacity k (1-23) 
 * and a packet payload size n (2-100). We first compute an adjusted buffer offset 
 * using func(), then compute a checksum-related triangle number using func2().
 * The high-level property: the final result is a valid non-negative offset 
 * that respects the buffer capacity constraints.
 */
int process_packet(size_t k, unsigned long n) {
    int offset;
    unsigned long triangle;
    int result;
    
    offset = func(k);
    //@ assert offset == func_spec(k);  // from func's ensures
    
    triangle = func2(n);
    //@ assert triangle == triangle_number(n);  // from func2's ensures
    
    result = offset + (int)(triangle % 24);  // keep triangle contribution small
    
    //@ assert result >= 0;
    //@ assert result <= 71;
    
    return result;
}
