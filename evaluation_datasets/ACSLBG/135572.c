#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate result_condition(integer a, integer b, bool r) =
        r == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/


bool func(unsigned int a, unsigned int b)
{
    bool is_possible = false;
    unsigned int temp_a = a;
    unsigned int temp_b = b;
    unsigned int temp_sum = a + b;

    
    while (temp_a >= 3)
    {
        temp_a -= 3;
    }
    if (temp_a == 0)
    {
        is_possible = true;
    }

    
    while (temp_b >= 3)
    {
        temp_b -= 3;
    }
    if (temp_b == 0)
    {
        is_possible = true;
    }

    
    while (temp_sum >= 3)
    {
        temp_sum -= 3;
    }
    if (temp_sum == 0)
    {
        is_possible = true;
    }

    //@ assert is_possible == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    return is_possible;
}
