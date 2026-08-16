#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == ((a * b) % 2 != 0);
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int ans;
    bool is_odd_result;
    unsigned int temp_ans;

    // Implementing the multiplication table for 1 <= a, b <= 3
    if (a == 1 || b == 1)
    {
        if (a == 1 && b == 1)
        {
            ans = 1;
        }
        else if (a == 1 && b == 2)
        {
            ans = 2;
        }
        else if (a == 1 && b == 3)
        {
            ans = 3;
        }
        else if (a == 2 && b == 1)
        {
            ans = 2;
        }
        else if (a == 3 && b == 1)
        {
            ans = 3;
        }
        else
        {
            ans = 0;
        }
    }
    else if (a == 2 || b == 2)
    {
        if (a == 2 && b == 2)
        {
            ans = 4;
        }
        else if (a == 2 && b == 3)
        {
            ans = 6;
        }
        else if (a == 3 && b == 2)
        {
            ans = 6;
        }
        else
        {
            ans = 0;
        }
    }
    else
    {
        ans = 9;
    }

    //@ assert ans == a * b;

    // Manually implement the modulus operation
    temp_ans = ans;
    /*@
        loop invariant 0 <= temp_ans <= ans;
        loop invariant temp_ans % 2 == ans % 2;
        loop assigns temp_ans;
    */
    while (temp_ans >= 2)
    {
        temp_ans -= 2;
    }

    is_odd_result = (temp_ans == 1);
    return is_odd_result;
}
