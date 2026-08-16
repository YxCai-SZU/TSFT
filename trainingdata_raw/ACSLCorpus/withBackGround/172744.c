#include <limits.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 10000;
    
    logic integer division_count(integer n, integer count) = n - count * 1000;
    
    lemma division_property:
        \forall integer n, count;
        valid_n(n) && 0 <= count && count <= n/1000 ==>
        division_count(n, count) >= 0;
    
    lemma modulus_property:
        \forall integer n, count;
        valid_n(n) && 0 <= count && count <= n/1000 && division_count(n, count) < 1000 ==>
        0 <= division_count(n, count);
*/

/*@
    requires valid_n(n);
    ensures \result == (n / 1000 + 1) * 1000 - n;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int count;
    
    result = 0;
    temp_n = n;
    count = 0;
    
    //@ assert valid_n(n);
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= temp_n <= n;
        loop invariant count >= 0;
        loop invariant temp_n == n - count * 1000;
        loop invariant count <= n / 1000;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 1000)
    {
        temp_n -= 1000;
        count += 1;
    }
    
    //@ assert temp_n < 1000;
    //@ assert temp_n == n - count * 1000;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant temp_n < 1000;
        loop invariant count >= 0;
        loop invariant temp_n == n - count * 1000;
        loop assigns temp_n;
        loop variant -temp_n;
    */
    while (temp_n < 0)
    {
        temp_n += 1000;
    }
    
    //@ assert 0 <= temp_n < 1000;
    
    result = (count + 1) * 1000 - n;
    
    return result;
}
