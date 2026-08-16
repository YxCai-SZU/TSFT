#include <stdbool.h>

/*@
    predicate is_divisible_by_2(integer n) = n % 2 == 0;
    predicate is_divisible_by_5(integer n) = n % 5 == 0;
*/

/*@
    requires 1 <= n <= 100000;
    ensures \result == (n % 2 == 0 || n % 5 == 0);
*/
bool func(int n)
{
    bool ok;
    int temp_n;
    bool is_divisible_by_2;
    bool is_divisible_by_5;
    
    ok = false;
    temp_n = n;
    is_divisible_by_2 = false;
    
    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n % 2 == n % 2;
        loop assigns temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        temp_n -= 2;
    }
    
    if (temp_n == 0)
    {
        is_divisible_by_2 = true;
    }
    
    temp_n = n;
    is_divisible_by_5 = false;
    
    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n % 5 == n % 5;
        loop assigns temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 5)
    {
        temp_n -= 5;
    }
    
    if (temp_n == 0)
    {
        is_divisible_by_5 = true;
    }
    
    ok = is_divisible_by_2 || is_divisible_by_5;
    
    //@ assert ok == (n % 2 == 0 || n % 5 == 0);
    
    return ok;
}

int main()
{
    return 0;
}
