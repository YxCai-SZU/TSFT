#include <stdint.h>
/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer triangle_sum(integer n) = n * (n + 1) / 2;
    
    lemma sum_bound: \forall integer n; valid_n(n) ==> triangle_sum(n) <= 5050;
*/

/*@
    requires valid_n(n);
    ensures \result == triangle_sum(n);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t res;
    
    //@ assert valid_n(n);
    //@ assert triangle_sum(n) <= 5050;
    
    res = n * (n + 1) / 2;
    
    //@ assert res == triangle_sum(n);
    return res;
}

int main()
{
    return 0;
}
