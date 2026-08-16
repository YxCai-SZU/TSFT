#include <stdbool.h>

/*@
    requires (0 <= (a) <= 23) && (0 <= (b) <= 23);
    ensures \result == (((a + b) % 24) < 6);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int sum;
    bool is_between;
    unsigned int temp_sum;

    sum = a + b;
    is_between = false;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum % 24 == sum % 24;
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 24)
    {
        temp_sum -= 24;
    }

    //@ assert temp_sum == ((a + b) % 24);
    
    if (temp_sum < 6)
    {
        is_between = true;
    }

    //@ assert is_between == (((a + b) % 24) < 6);
    
    return is_between;
}
