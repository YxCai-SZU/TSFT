#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_array(int64_t* arr, integer len) =
    len > 0 && len <= 200 &&
    \forall integer i; 0 <= i < len ==> arr[i] > 0 && arr[i] <= 1000000000;
*/

/*@ lemma index_result_relation:
    \forall integer index, integer result;
    0 <= result <= (int32_t)index ==> result <= (int32_t)index;
*/

/*@ requires n > 0 && n <= 200;
    requires valid_array(a, n);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= (int32_t)n;
*/
int32_t func(int64_t n, int64_t* a) {
    // Variable declarations
    int64_t before = 0;
    int32_t result = 0;
    int64_t index = 0;
    
    // Precondition check
    //@ assert valid_array(a, n);
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant result >= 0;
        loop invariant result <= (int32_t)index;
        loop invariant \forall integer i; 0 <= i < n ==> a[i] > 0 && a[i] <= 1000000000;
        loop assigns before, result, index;
        loop variant n - index;
    */
    while (index < n) {
        int64_t ai = a[index];
        
        if (before >= ai) {
            result += 1;
        } else {
            before = ai;
        }
        
        index += 1;
        
        //@ assert result <= (int32_t)index;
    }
    
    // Postcondition verification
    //@ assert result >= 0;
    //@ assert result <= (int32_t)n;
    
    return result;
}
