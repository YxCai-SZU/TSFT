#include <stdbool.h>

/*@ predicate is_all_even_result(integer n, bool result) =
    result == (n == 0 || n == 1 || n == 2 || n == 3 || n == 4);
*/

/*@ requires n >= 0;
    ensures \result == (n == 0 || n == 1 || n == 2 || n == 3 || n == 4);
    assigns \nothing;
*/
bool is_all_even(int n)
{
    //@ assert n >= 0;
    
    bool result;
    
    if (n == 0 || n == 1 || n == 2 || n == 3 || n == 4)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert is_all_even_result(n, result);
    return result;
}
