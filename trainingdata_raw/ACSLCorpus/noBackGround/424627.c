#include <stdbool.h>

/*@
    requires 1 <= n <= 1000000;
    ensures \result == ((n % 2 == 0 && n >= 100) || (n % 2 != 0 && n >= 200));
    assigns \nothing;
*/
bool func(int n)
{
    bool is_even_bool;
    bool is_odd_bool;
    bool is_sufficiently_large_bool;
    bool is_odd_and_large_enough_bool;
    bool result;

    is_even_bool = (n % 2 == 0);
    //@ assert is_even_bool == (n % 2 == 0);
    
    is_odd_bool = !is_even_bool;
    //@ assert is_odd_bool == (n % 2 != 0);
    
    is_sufficiently_large_bool = (n >= 100);
    //@ assert is_sufficiently_large_bool == (n >= 100);
    
    is_odd_and_large_enough_bool = (n >= 200);
    //@ assert is_odd_and_large_enough_bool == (n >= 200);
    
    result = (is_even_bool && is_sufficiently_large_bool) || (is_odd_bool && is_odd_and_large_enough_bool);
    //@ assert result == ((n % 2 == 0 && n >= 100) || (n % 2 != 0 && n >= 200));
    
    return result;
}
