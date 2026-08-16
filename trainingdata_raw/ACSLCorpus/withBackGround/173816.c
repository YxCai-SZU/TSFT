#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 100;
    
    logic integer compute_result(integer i) = i * 6;
*/

/*@
    requires is_valid_range(n);
    ensures \result == n * 2 * 3;
    assigns \nothing;
*/
int func(int n)
{
    int result = 0;
    int i = 0;
    
    //@ ghost int original_n = n;
    
    /*@
        loop invariant 0 <= i <= original_n;
        loop invariant result == compute_result(i);
        loop assigns result, i;
        loop variant original_n - i;
    */
    while (i < n)
    {
        result = result + 6;
        i = i + 1;
    }
    
    //@ assert result == original_n * 2 * 3;
    return result;
}

int main(void)
{
    return 0;
}
