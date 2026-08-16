#include <stdint.h>

/*@
    predicate is_valid_x(integer x) = 1 <= x && x <= 1000000000000000;
    
    logic integer division_by_subtraction(integer x, integer divisor) = x / divisor;
    
    lemma ans_bounds: \forall integer x, integer q, integer q111, integer q1111;
        is_valid_x(x) && 0 <= q && q <= division_by_subtraction(x, 11) &&
        0 <= q111 && q111 <= division_by_subtraction(x, 111) &&
        0 <= q1111 && q1111 <= division_by_subtraction(x, 1111) ==>
        0 <= 2*q + (q111 > 0 ? 1 : 0) + (q1111 > 0 ? 1 : 0) <= 2*x;
*/

/*@
    requires is_valid_x(x);
    ensures 0 <= \result <= 2*x;
    assigns \nothing;
*/
int64_t func(int64_t x) {
    int64_t q = 0;
    int64_t temp_x = x;
    int64_t divisor = 11;
    int64_t q_111 = 0;
    int64_t temp_x_111 = x;
    int64_t divisor_111 = 111;
    int64_t q_1111 = 0;
    int64_t temp_x_1111 = x;
    int64_t divisor_1111 = 1111;
    int64_t ans = 0;
    
    /*@
        loop invariant 1 <= x <= 1000000000000000;
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= q <= x / 11;
        loop invariant temp_x == x - 11 * q;
        loop assigns temp_x, q;
        loop variant temp_x;
    */
    while (temp_x >= divisor) {
        //@ assert temp_x >= 11;
        temp_x -= divisor;
        q += 1;
    }
    
    /*@
        loop invariant 1 <= x <= 1000000000000000;
        loop invariant 0 <= temp_x_111 <= x;
        loop invariant 0 <= q_111 <= x / 111;
        loop invariant temp_x_111 == x - 111 * q_111;
        loop assigns temp_x_111, q_111;
        loop variant temp_x_111;
    */
    while (temp_x_111 >= divisor_111) {
        //@ assert temp_x_111 >= 111;
        temp_x_111 -= divisor_111;
        q_111 += 1;
    }
    
    /*@
        loop invariant 1 <= x <= 1000000000000000;
        loop invariant 0 <= temp_x_1111 <= x;
        loop invariant 0 <= q_1111 <= x / 1111;
        loop invariant temp_x_1111 == x - 1111 * q_1111;
        loop assigns temp_x_1111, q_1111;
        loop variant temp_x_1111;
    */
    while (temp_x_1111 >= divisor_1111) {
        //@ assert temp_x_1111 >= 1111;
        temp_x_1111 -= divisor_1111;
        q_1111 += 1;
    }
    
    ans = 2 * q;
    //@ assert 0 <= ans <= 2*x;
    ans += (q_111 > 0) ? 1 : 0;
    //@ assert 0 <= ans <= 2*x + 1;
    ans += (q_1111 > 0) ? 1 : 0;
    //@ assert 0 <= ans <= 2*x + 2;
    
    //@ assert ans <= 2*x;
    return ans;
}

int main() {
    return 0;
}
