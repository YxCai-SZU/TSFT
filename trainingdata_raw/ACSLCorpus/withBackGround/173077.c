#include <stdint.h>

/*@
    predicate valid_input(integer n) = 0 <= n <= 65535;

    logic integer triangular_num(integer n) = (n * (n + 1)) / 2;

    lemma triangular_bound: \forall integer n; valid_input(n) ==> triangular_num(n) <= n * n;
    lemma no_overflow_mul: \forall integer n; valid_input(n) ==> n * n <= 4294967295;
    lemma no_overflow_tri: \forall integer n; valid_input(n) ==> triangular_num(n) <= 2147483647;
*/

/*@
    requires valid_input(n);
    ensures \result == triangular_num(n);
    ensures \result <= n * n;
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    //@ assert valid_input(n);
    
    //@ assert n * (n + 1) <= 65535 * (65535 + 1);
    //@ assert n * (n + 1) >= n * n;
    //@ assert n * (n + 1) / 2 <= 2147483647;
    //@ assert n * n <= 4294967295;
    //@ assert n * (n + 1) / 2 <= n * n;
    
    return (n * (n + 1)) / 2;
}
