#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 1 <= x <= 100000;
    
    logic integer compute_n(integer x) = x / 100;
    logic integer compute_remained(integer x) = x % 100;
    
    lemma remainder_bound: \forall integer x; is_valid_input(x) ==> 0 <= compute_remained(x) < 100;
    lemma n_bound: \forall integer x; is_valid_input(x) ==> 0 <= compute_n(x) <= 1000;
*/

/*@
    requires is_valid_input(x);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    uint32_t n;
    uint32_t remained;
    uint32_t a;
    
    n = x / 100;
    remained = x % 100;
    a = remained;
    
    //@ assert n == compute_n(x);
    //@ assert remained == compute_remained(x);
    
    if (remained <= 5 * n)
    {
        //@ assert remained <= 5 * n;
        return 1;
    }
    else
    {
        //@ assert remained > 5 * n;
        return 0;
    }
}
