#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer compute_x(integer n) = n * 800;
    logic integer compute_y(integer n) = n / 15;
    logic integer compute_result(integer n) = compute_x(n) - compute_y(n) * 200;

    lemma x_bound: \forall integer n; valid_n(n) ==> compute_x(n) <= 80000;
    lemma y_bound: \forall integer n; valid_n(n) ==> compute_y(n) * 200 <= 20000;
*/

/*@
    requires valid_n(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t x;
    uint32_t y;
    int32_t ans;
    
    // Precondition verification
    //@ assert valid_n(n);
    
    // Arithmetic bounds verification
    //@ assert n * 800 <= 80000;
    //@ assert (n / 15) * 200 <= 20000;
    
    x = n * 800;
    y = n / 15;
    
    // Loop-free logic verification
    //@ assert x == compute_x(n);
    //@ assert y == compute_y(n);
    
    ans = (int32_t)x - (int32_t)y * 200;
    
    // Postcondition verification
    //@ assert ans == compute_result(n);
    
    return ans;
}
