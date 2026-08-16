#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 1000000000;
    
    logic integer target_result(integer n) = (n * (n - 1)) / 2;
    
    lemma no_overflow: \forall integer n; is_valid_n(n) ==> n * (n - 1) <= 18446744073709551615;
*/

/*@
    requires is_valid_n(n);
    ensures \result == target_result(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t result;
    uint64_t count;
    
    //@ assert n > 0;
    //@ assert n <= 1000000000;
    //@ assert n * (n - 1) <= 18446744073709551615;
    
    result = n * (n - 1);
    count = 0;
    
    /*@
        loop invariant 1 <= n <= 1000000000;
        loop invariant result >= 0;
        loop invariant count >= 0;
        loop invariant result == n * (n - 1) - 2 * count;
        loop invariant count <= (n * (n - 1)) / 2;
        loop assigns result, count;
        loop variant result;
    */
    while (result >= 2)
    {
        result -= 2;
        count += 1;
    }
    
    return count;
}
