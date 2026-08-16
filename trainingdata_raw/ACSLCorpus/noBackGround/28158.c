#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> 
            ((((a) % 2 == 0) && ((b) % 2 != 0)) || (((a) % 2 != 0) && ((b) % 2 == 0)));
*/
bool func(unsigned long a, unsigned long b)
{
    bool is_even_a = false;
    bool is_even_b = false;
    unsigned long temp_a = a;
    unsigned long temp_b = b;
    
    // Check if a is even
    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant a % 2 == temp_a % 2;
        loop assigns temp_a;
        loop variant temp_a;
    */
    while (temp_a >= 2)
    {
        //@ assert temp_a % 2 == (temp_a - 2) % 2;
        temp_a -= 2;
    }
    
    if (temp_a == 0)
    {
        is_even_a = true;
    }
    
    // Check if b is even
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant b % 2 == temp_b % 2;
        loop assigns temp_b;
        loop variant temp_b;
    */
    while (temp_b >= 2)
    {
        //@ assert temp_b % 2 == (temp_b - 2) % 2;
        temp_b -= 2;
    }
    
    if (temp_b == 0)
    {
        is_even_b = true;
    }
    
    //@ assert is_even_a == (a % 2 == 0);
    //@ assert is_even_b == (b % 2 == 0);
    
    if ((is_even_a && !is_even_b) || (!is_even_a && is_even_b))
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
