#include <limits.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 1000;
    
    logic integer division_result(integer n) = n / 3;
*/

/*@
    requires valid_range(n);
    ensures \result == division_result(n);
    assigns \nothing;
*/
int func(int n)
{
    int count = 0;
    int temp_n = n;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= n / 3;
        loop invariant temp_n == n - 3 * count;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        //@ assert temp_n >= 3;
        temp_n -= 3;
        count += 1;
    }
    
    //@ assert count == n / 3;
    return count;
}
