#include <stdbool.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    ensures \result == true <==> 
            (A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0);
    assigns \nothing;
*/
bool func(int A, int B)
{
    bool is_possible = false;
    int temp_a = A;
    int temp_b = B;
    int temp_sum = A + B;
    
    // Check if A is divisible by 3
    /*@
        loop invariant 0 <= temp_a <= A;
        loop invariant temp_a % 3 == A % 3;
        loop assigns temp_a;
    */
    while (temp_a >= 3)
    {
        //@ assert temp_a % 3 == A % 3;
        temp_a -= 3;
    }
    
    if (temp_a == 0)
    {
        is_possible = true;
    }
    
    // Check if B is divisible by 3
    /*@
        loop invariant 0 <= temp_b <= B;
        loop invariant temp_b % 3 == B % 3;
        loop assigns temp_b;
    */
    while (temp_b >= 3)
    {
        //@ assert temp_b % 3 == B % 3;
        temp_b -= 3;
    }
    
    if (temp_b == 0)
    {
        is_possible = true;
    }
    
    // Check if A + B is divisible by 3
    /*@
        loop invariant 0 <= temp_sum <= A + B;
        loop invariant temp_sum % 3 == (A + B) % 3;
        loop assigns temp_sum;
    */
    while (temp_sum >= 3)
    {
        //@ assert temp_sum % 3 == (A + B) % 3;
        temp_sum -= 3;
    }
    
    if (temp_sum == 0)
    {
        is_possible = true;
    }
    
    //@ assert is_possible == true <==> (A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0);
    return is_possible;
}
