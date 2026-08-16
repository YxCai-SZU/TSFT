#include <stdint.h>

/*@
    predicate bounds(integer a, integer b, integer t) =
        1 <= a <= 20 && 1 <= b <= 20 && 1 <= t <= 20;

    logic integer safe_div(integer t, integer a) = t / a;
    logic integer safe_mul(integer d, integer b) = d * b;
    logic integer result_expr(integer t, integer a, integer b) = 
        safe_mul(safe_div(t, a), b);

    lemma div_bound: \forall integer t, a; 
        bounds(a, 1, t) ==> safe_div(t, a) <= 20;
    lemma mul_bound: \forall integer d, b; 
        bounds(1, b, 1) && d <= 20 ==> safe_mul(d, b) <= 400;
*/

/*@
    requires bounds(A, B, T);
    ensures \result == result_expr(T, A, B);
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t T) {
    // Variable declarations at scope top
    uint32_t ans;
    
    //@ assert A > 0 && A <= 20;
    //@ assert B > 0 && B <= 20;
    //@ assert T > 0 && T <= 20;
    
    //@ assert A <= 20 && B <= 20 && T <= 20;
    
    //@ assert T / A <= 20;
    //@ assert (T / A) * B <= 400;
    
    //@ assert T / A <= 20;
    //@ assert (T / A) * B <= 400;
    
    ans = T / A * B;
    return ans;
}
