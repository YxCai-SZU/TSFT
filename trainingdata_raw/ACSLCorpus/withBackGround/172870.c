#include <stdint.h>
#include <stdbool.h>

/*@ predicate is_valid_array(integer n, uint32_t *a) =
    n >= 1 && n <= 200000 &&
    \valid(a + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= n;
*/

/*@ predicate loop_invariant(integer n, uint32_t *a, integer index, uint32_t count) =
    index <= n &&
    count <= index &&
    is_valid_array(n, a);
*/

/*@
    requires is_valid_array(n, a);
    ensures \result <= n;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t *a) {
    uint32_t count = 0;
    uint32_t index = 0;
    
    //@ ghost uint32_t old_n = n;
    
    /*@
        loop invariant loop_invariant(old_n, a, index, count);
        loop invariant 0 <= index <= old_n;
        loop invariant 0 <= count <= index;
        loop assigns count, index;
        loop variant old_n - index;
    */
    while (index < n) {
        uint32_t value = a[index];
        
        //@ assert value >= 1 && value <= n;
        
        if (value == count + 1) {
            //@ assert count + 1 <= n;
            count = count + 1;
        }
        
        //@ assert count <= index + 1;
        index = index + 1;
    }
    
    //@ assert count <= n;
    return count;
}
