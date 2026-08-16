#include <stdint.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 100;

    logic integer compute_x(integer n) = n * 800;
    logic integer compute_y(integer n) = n / 15;
    logic integer compute_z(integer n) = compute_y(n) * 200;
    logic integer compute_result(integer n) = compute_x(n) - compute_z(n);

    lemma x_bound: \forall integer n; valid_range(n) ==> compute_x(n) <= 80000;
    lemma y_bound: \forall integer n; valid_range(n) ==> compute_y(n) <= 6;
    lemma z_bound: \forall integer n; valid_range(n) ==> compute_z(n) <= 1200;
    lemma result_bound: \forall integer n; valid_range(n) ==> compute_result(n) <= 80000;
    lemma result_correct: \forall integer n; valid_range(n) ==> compute_result(n) == n * 800 - (n / 15) * 200;
*/

/*@
    requires 1 <= n <= 100;
    ensures \result == n * 800 - (n / 15) * 200;
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    uint32_t x;
    uint32_t y;
    uint32_t z;
    int32_t result;

    //@ assert valid_range(n);
    
    x = n * 800;
    //@ assert x == compute_x(n);
    
    y = n / 15;
    //@ assert y == compute_y(n);
    
    z = y * 200;
    //@ assert z == compute_z(n);
    
    result = (int32_t)(x - z);
    //@ assert result == compute_result(n);
    
    return result;
}
