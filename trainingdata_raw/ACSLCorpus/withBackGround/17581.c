#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 100;
    
    logic integer division_by_2(integer n) = n / 2;
    logic integer remainder_by_2(integer n) = n % 2;
    logic integer target_result(integer n) = division_by_2(n) + remainder_by_2(n);
*/

/*@
    requires is_valid_range(n);
    ensures \result == target_result(n);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int count;
    bool is_odd;
    
    result = 0;
    temp_n = n;
    count = 0;
    is_odd = false;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n == n - 2 * count;
        loop invariant 0 <= count <= division_by_2(n);
        loop invariant count == (n - temp_n) / 2;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        count += 1;
    }
    
    if (temp_n == 1)
    {
        is_odd = true;
    }
    
    if (is_odd)
    {
        result = count + 1;
    }
    else
    {
        result = count;
    }
    
    //@ assert result == target_result(n);
    return result;
}
