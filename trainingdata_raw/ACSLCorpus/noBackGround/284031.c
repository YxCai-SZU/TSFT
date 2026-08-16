#include <stdbool.h>

/*@
    requires 1 <= a <= 16;
    requires 1 <= b <= 16;
    requires a + b <= 16;
    ensures \result == true <==> (a <= 8 && b <= 8);
*/
bool func(long a, long b)
{
    bool result = false;
    bool is_a_less_than_or_equal_to_8 = false;
    bool is_b_less_than_or_equal_to_8 = false;

    // Check if a is less than or equal to 8
    if (a <= 8)
    {
        is_a_less_than_or_equal_to_8 = true;
    }

    // Check if b is less than or equal to 8
    if (b <= 8)
    {
        is_b_less_than_or_equal_to_8 = true;
    }

    // If both conditions are true, set result to true
    if (is_a_less_than_or_equal_to_8 && is_b_less_than_or_equal_to_8)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> (a <= 8 && b <= 8);

    return result;
}
