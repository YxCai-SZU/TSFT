#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> 
            (a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0);
*/
bool func(unsigned long a, unsigned long b)
{
    bool is_a_even;
    bool is_b_even;
    unsigned long temp_a;
    unsigned long temp_b;
    
    // Check parity of a
    temp_a = a;
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant temp_a <= a;
        loop invariant temp_a >= 0;
        loop invariant temp_a % 2 == a % 2;
        loop assigns temp_a;
    */
    while (temp_a >= 2)
    {
        temp_a -= 2;
    }
    is_a_even = (temp_a == 0);
    
    // Check parity of b
    temp_b = b;
    /*@
        loop invariant 1 <= b <= 100;
        loop invariant temp_b <= b;
        loop invariant temp_b >= 0;
        loop invariant temp_b % 2 == b % 2;
        loop assigns temp_b;
    */
    while (temp_b >= 2)
    {
        temp_b -= 2;
    }
    is_b_even = (temp_b == 0);
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    if ((is_a_even && is_b_even) || (!is_a_even && !is_b_even))
    {
        return true;
    }
    else
    {
        return false;
    }
}
