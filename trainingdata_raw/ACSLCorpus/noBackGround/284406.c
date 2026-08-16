#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> ((c) >= (a) && (c) <= (b));
*/
bool func(int a, int b, int c)
{
    bool is_within = true;
    
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    
    if (c < a)
    {
        is_within = false;
    }
    
    if (c > b)
    {
        is_within = false;
    }
    
    //@ assert is_within == true <==> ((c) >= (a) && (c) <= (b));
    
    return is_within;
}
