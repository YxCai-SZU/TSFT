#include <stdint.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 100;
    
    logic integer division_by_15(integer n) = n / 15;
    
    logic integer expected_result(integer n) = n * 800 - (division_by_15(n) * 200);
*/

/*@
    requires valid_range(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    // Variable declarations at top of scope
    int64_t result;
    int64_t quotient = 0;
    int64_t temp_n = n;
    
    result = n * 800;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant quotient >= 0;
        loop invariant temp_n == n - 15 * quotient;
        loop invariant valid_range(n);
        loop assigns temp_n, quotient;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        quotient += 1;
    }
    
    result -= quotient * 200;
    
    //@ assert quotient == division_by_15(n);
    //@ assert result == n * 800 - (quotient * 200);
    //@ assert result == expected_result(n);
    
    return result;
}

/*@
    lemma division_property: 
        \forall integer n; valid_range(n) ==> 
            (n - 15 * division_by_15(n)) >= 0 && 
            (n - 15 * division_by_15(n)) < 15;
*/

int main()
{
    return 0;
}
