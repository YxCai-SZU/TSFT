#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> 
            (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    bool is_a_multiple_of_3 = false;
    bool is_b_multiple_of_3 = false;
    bool is_sum_multiple_of_3 = false;
    unsigned int temp_a = a;
    unsigned int temp_b = b;
    unsigned int temp_sum = a + b;
    
    // Check if a is multiple of 3
    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant temp_a % 3 == a % 3;
        loop assigns temp_a;
    */
    while (temp_a >= 3)
    {
        temp_a -= 3;
    }
    if (temp_a == 0)
    {
        is_a_multiple_of_3 = true;
    }
    
    // Check if b is multiple of 3
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant temp_b % 3 == b % 3;
        loop assigns temp_b;
    */
    while (temp_b >= 3)
    {
        temp_b -= 3;
    }
    if (temp_b == 0)
    {
        is_b_multiple_of_3 = true;
    }
    
    // Check if a+b is multiple of 3
    /*@
        loop invariant 0 <= temp_sum <= a + b;
        loop invariant temp_sum % 3 == (a + b) % 3;
        loop assigns temp_sum;
    */
    while (temp_sum >= 3)
    {
        temp_sum -= 3;
    }
    if (temp_sum == 0)
    {
        is_sum_multiple_of_3 = true;
    }
    
    bool answer = is_a_multiple_of_3 || is_b_multiple_of_3 || is_sum_multiple_of_3;
    
    //@ assert answer == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    
    return answer;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
