/*@
    predicate is_divisible_by_2(integer k) = k % 2 == 0;
    predicate is_divisible_by_5(integer k) = k % 5 == 0;
    
    lemma mod_preservation_2: \forall integer k, k_copy; 
        0 <= k_copy <= k && k_copy % 2 == k % 2 ==> 
        (k_copy == 0 ==> k % 2 == 0);
        
    lemma mod_preservation_5: \forall integer k, k_copy; 
        0 <= k_copy <= k && k_copy % 5 == k % 5 ==> 
        (k_copy == 0 ==> k % 5 == 0);
*/

#include <stdbool.h>

/*@
    requires 1 <= k <= 100000;
    ensures \result == true <==> (k % 2 == 0 || k % 5 == 0);
    assigns \nothing;
*/
bool func(unsigned int k) {
    unsigned int k_copy;
    bool is_divisible_by_2;
    bool is_divisible_by_5;
    
    // Check if k is divisible by 2
    k_copy = k;
    is_divisible_by_2 = false;
    
    /*@
        loop invariant 0 <= k_copy <= k;
        loop invariant k_copy % 2 == k % 2;
        loop assigns k_copy;
        loop variant k_copy;
    */
    while (k_copy >= 2) {
        k_copy -= 2;
    }
    
    if (k_copy == 0) {
        is_divisible_by_2 = true;
    }
    
    // Check if k is divisible by 5
    k_copy = k;
    is_divisible_by_5 = false;
    
    /*@
        loop invariant 0 <= k_copy <= k;
        loop invariant k_copy % 5 == k % 5;
        loop assigns k_copy;
        loop variant k_copy;
    */
    while (k_copy >= 5) {
        k_copy -= 5;
    }
    
    if (k_copy == 0) {
        is_divisible_by_5 = true;
    }
    
    //@ assert is_divisible_by_2 == (k % 2 == 0);
    //@ assert is_divisible_by_5 == (k % 5 == 0);
    
    return is_divisible_by_2 || is_divisible_by_5;
}
