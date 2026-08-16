#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (b % 3 == 0 || b % 3 == 2 || (b % 3 == 1 && a % 2 == 0));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    bool a_is_even = false;
    unsigned int b_mod_3 = 0;
    unsigned int temp_a = a;
    unsigned int temp_b = b;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 0 <= temp_a <= a;
        loop invariant temp_a % 2 == a % 2;
        loop assigns temp_a;
        loop variant temp_a;
    */
    while (temp_a >= 2)
    {
        //@ assert temp_a >= 2;
        temp_a -= 2;
        //@ assert temp_a >= 0;
    }
    
    //@ assert temp_a == 0 || temp_a == 1;
    if (temp_a == 0)
    {
        a_is_even = true;
    }
    //@ assert a_is_even == (a % 2 == 0);
    
    /*@
        loop invariant 1 <= b <= 100;
        loop invariant 0 <= temp_b <= b;
        loop invariant temp_b % 3 == b % 3;
        loop assigns temp_b;
        loop variant temp_b;
    */
    while (temp_b >= 3)
    {
        //@ assert temp_b >= 3;
        temp_b -= 3;
        //@ assert temp_b >= 0;
    }
    
    b_mod_3 = temp_b;
    //@ assert b_mod_3 == b % 3;
    
    if (b_mod_3 == 0 || b_mod_3 == 2 || (b_mod_3 == 1 && a_is_even))
    {
        //@ assert b_mod_3 == 0 || b_mod_3 == 2 || (b_mod_3 == 1 && a_is_even);
        return true;
    }
    else
    {
        //@ assert !(b_mod_3 == 0 || b_mod_3 == 2 || (b_mod_3 == 1 && a_is_even));
        return false;
    }
}

int main()
{
    return 0;
}
