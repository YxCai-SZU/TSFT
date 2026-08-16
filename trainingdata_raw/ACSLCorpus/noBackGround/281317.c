#include <stdbool.h>

/*@
    requires (1 <= (N) && (N) <= 9);
    ensures \result == true <==> ((N) == 3 || (N) == 5 || (N) == 7);
    assigns \nothing;
*/
bool func(unsigned int N)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= N && N <= 9;
    
    result = (N == 3 || N == 5 || N == 7);
    return result;
}
