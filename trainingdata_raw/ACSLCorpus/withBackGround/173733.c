#include <stdint.h>

/*@
    predicate is_valid_n(uint32_t n) = n <= 2896;

    logic integer triangular_num(integer n) = n * (n + 1) / 2;

    lemma triangular_bound: \forall integer n; 0 <= n <= 2896 ==> n * (n + 1) <= 2896 * 2897;
    lemma no_overflow: 2896 * 2897 <= 4294967295;
*/

/*@
    requires is_valid_n(n);
    ensures \result == triangular_num(n);
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t ret;

    //@ assert n <= 2896;
    //@ assert n * (n + 1) <= 2896 * 2897;
    
    ret = n * (n + 1) / 2;
    
    //@ assert ret == triangular_num(n);
    return ret;
}
