#include <limits.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    logic integer compute_result(integer n, integer count) = n * 800 - 200 * count;
    logic integer count_value(integer n) = n / 15;
*/

/*@
    requires is_valid_n(n);
    ensures \result == compute_result(n, count_value(n));
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int count;
    int temp_n;
    
    //@ assert is_valid_n(n);
    result = n * 800;
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= count && count <= n / 15;
        loop invariant temp_n >= 0;
        loop invariant temp_n == n - 15 * count;
        loop invariant count > 0 ==> result == n * 800;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
    }
    
    //@ assert 0 <= count && count <= 6;
    result = result - 200 * count;
    return result;
}

int main()
{
    return 0;
}
