#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> 
            (a % 3 == 0) || (b % 3 == 0) || ((a + b) % 3 == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool is_divisible_by_3 = false;
    int temp_a = a;
    int temp_b = b;
    int temp_ab = a + b;
    
    // Check if a is divisible by 3
    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant temp_a % 3 == a % 3;
        loop assigns temp_a;
        loop variant temp_a;
    */
    while (temp_a >= 3)
    {
        temp_a -= 3;
        //@ assert temp_a % 3 == a % 3;
    }
    
    if (temp_a == 0)
    {
        is_divisible_by_3 = true;
    }
    
    // Check if b is divisible by 3
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant temp_b % 3 == b % 3;
        loop assigns temp_b;
        loop variant temp_b;
    */
    while (temp_b >= 3)
    {
        temp_b -= 3;
        //@ assert temp_b % 3 == b % 3;
    }
    
    if (temp_b == 0)
    {
        is_divisible_by_3 = true;
    }
    
    // Check if (a + b) is divisible by 3
    /*@
        loop invariant 0 <= temp_ab <= a + b;
        loop invariant temp_ab % 3 == (a + b) % 3;
        loop assigns temp_ab;
        loop variant temp_ab;
    */
    while (temp_ab >= 3)
    {
        temp_ab -= 3;
        //@ assert temp_ab % 3 == (a + b) % 3;
    }
    
    if (temp_ab == 0)
    {
        is_divisible_by_3 = true;
    }
    
    return is_divisible_by_3;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
