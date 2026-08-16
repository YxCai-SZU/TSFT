#include <stdint.h>
#include <stddef.h>

/*@
    predicate is_valid_index(int i, integer len) =
        0 <= i && i < len;

    predicate element_in_bounds(integer val) =
        val <= 0x100000000;

    logic integer vector_len{L}(uint32_t *v, integer len) = len;

    predicate vector_bounds{L}(uint32_t *v, integer len) =
        \forall integer i; 0 <= i < len ==> element_in_bounds((integer)v[i]);

    lemma max_ge_first:
        \forall uint32_t *v, integer len, uint32_t max_val;
        vector_bounds(v, len) && len > 0 && max_val >= (integer)v[0] ==>
        max_val >= (integer)v[0];
*/

/*@
    requires \valid_read(v + (0 .. len-1));
    requires len > 0;
    requires vector_bounds(v, len);
    assigns \nothing;
    ensures \result <= 0x100000000;
    ensures \result >= v[0];
    ensures \forall integer i; 0 <= i < len ==> \result >= (integer)v[i];
*/
uint32_t func(uint32_t *v, size_t len) {
    uint32_t max_value;
    size_t i;
    
    max_value = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant len > 0;
        loop invariant \forall integer j; 0 <= j < i ==> max_value >= (integer)v[j];
        loop invariant vector_bounds(v, len);
        loop assigns i, max_value;
        loop variant len - i;
    */
    while (i < len) {
        if (v[i] > max_value) {
            max_value = v[i];
        }
        i++;
    }
    
    //@ assert max_value <= 0x100000000;
    //@ assert max_value >= v[0];
    //@ assert \forall integer i; 0 <= i < len ==> max_value >= (integer)v[i];
    
    return max_value;
}
