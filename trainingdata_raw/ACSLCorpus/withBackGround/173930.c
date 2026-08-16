#include <stdint.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 100;

    logic integer discount_count(integer n) = n / 15;

    logic integer final_result(integer n) = 
        n * 800 - discount_count(n) * 200;

    lemma discount_bound: 
        \forall integer n; valid_range(n) ==> 0 <= discount_count(n) <= 6;
*/

/*@
    requires valid_range(n);
    ensures \result == final_result(n);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t count;
    int64_t temp_n;
    
    //@ assert valid_range(n);
    
    result = n * 800;
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= discount_count(n);
        loop invariant temp_n == n - count * 15;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
        //@ assert temp_n == n - count * 15;
    }
    
    //@ assert count == discount_count(n);
    result = result - count * 200;
    
    //@ assert result == final_result(n);
    return result;
}
