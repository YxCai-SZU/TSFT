#include <stdbool.h>

/*@
    predicate is_odd(integer x) = (x % 2) == 1;
    predicate is_prime_candidate(integer x) = x == 3 || x == 5 || x == 7;
*/

/*@
    requires 1 <= x <= 9;
    ensures \result == (x == 3 || x == 5 || x == 7);
    assigns \nothing;
*/
bool func(unsigned int x)
{
    bool result;
    
    //@ assert (x % 2 == 0) || (x % 2 == 1);
    //@ assert (x % 2 == 0) ==> !is_odd(x);
    //@ assert (x % 2 == 1) ==> is_odd(x);
    
    result = (x == 3 || x == 5 || x == 7);
    
    //@ assert result == (x == 3 || x == 5 || x == 7);
    return result;
}

int main()
{
    return 0;
}
