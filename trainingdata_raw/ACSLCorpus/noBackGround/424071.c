#include <stdbool.h>

/*@
    requires (1 <= (a) <= 13) && (1 <= (b) <= 13) && (1 <= (c) <= 13);
    ensures \result == true <==> a + b + c >= 22;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    bool is_greater_or_equal_22;
    bool is_bust;
    bool result;

    sum = a + b + c;
    is_greater_or_equal_22 = false;
    is_bust = false;

    //@ assert (1 <= (a) <= 13) && (1 <= (b) <= 13) && (1 <= (c) <= 13);
    
    if (sum >= 22)
    {
        is_greater_or_equal_22 = true;
    }

    if (sum >= 22)
    {
        is_bust = true;
    }

    //@ assert is_greater_or_equal_22 == (sum >= 22);
    //@ assert is_bust == (sum >= 22);

    result = (is_greater_or_equal_22 || is_bust) ? true : false;

    //@ assert result == (sum >= 22);
    return result;
}
