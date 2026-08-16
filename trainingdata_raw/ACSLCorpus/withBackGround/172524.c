#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate result_in_range(integer r) = -1 <= r && r <= 2000;
    logic integer compute_c(integer a, integer b) = a * 8 + b * 10;
    logic integer compute_result(integer a, integer b) = (compute_c(a, b) + 1) / 2;
    predicate result_correct(integer a, integer b, integer r) = 
        r == -1 || r == compute_result(a, b);
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures result_in_range(\result);
    ensures result_correct(a, b, \result);
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t c;
    int32_t result;
    uint32_t temp_c;
    
    c = a * 8 + b * 10;
    result = 0;
    temp_c = c + 1;
    
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant c == a * 8 + b * 10;
        loop invariant 0 <= temp_c;
        loop invariant temp_c <= c + 1;
        loop invariant 0 <= result;
        loop invariant result <= (c + 1) / 2;
        loop invariant temp_c + 2 * result == c + 1;
        loop assigns result, temp_c;
    */
    while (temp_c > 1) {
        result += 1;
        temp_c -= 2;
    }
    
    //@ assert result == (c + 1) / 2;
    
    if (result > 2000) {
        //@ assert result_correct(a, b, -1);
        return -1;
    }
    
    //@ assert result_correct(a, b, result);
    return result;
}
