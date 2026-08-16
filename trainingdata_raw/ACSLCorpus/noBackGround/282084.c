#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(int a, int b)
{
    int sum;
    bool is_sum_divisible_by_3;
    int temp;
    bool is_a_divisible_by_3;
    bool is_b_divisible_by_3;
    
    sum = a + b;
    is_sum_divisible_by_3 = false;
    
    // Check if a is divisible by 3
    temp = a;
    is_a_divisible_by_3 = false;
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant temp >= 0;
        loop invariant temp <= a;
        loop invariant temp % 3 == a % 3;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 3)
    {
        temp -= 3;
    }
    if (temp == 0)
    {
        is_a_divisible_by_3 = true;
    }
    
    // Check if b is divisible by 3
    temp = b;
    is_b_divisible_by_3 = false;
    /*@
        loop invariant 1 <= b <= 100;
        loop invariant temp >= 0;
        loop invariant temp <= b;
        loop invariant temp % 3 == b % 3;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 3)
    {
        temp -= 3;
    }
    if (temp == 0)
    {
        is_b_divisible_by_3 = true;
    }
    
    // Check if sum is divisible by 3
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant sum >= 0;
        loop invariant sum <= a + b;
        loop invariant sum % 3 == (a + b) % 3;
        loop assigns sum;
        loop variant sum;
    */
    while (sum >= 3)
    {
        sum -= 3;
    }
    if (sum == 0)
    {
        is_sum_divisible_by_3 = true;
    }
    
    if (is_a_divisible_by_3 || is_b_divisible_by_3 || is_sum_divisible_by_3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    return 0;
}
