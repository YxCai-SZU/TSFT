#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (b) != (c)) ||
        ((a) == (c) && (c) != (b)) ||
        ((b) == (c) && (c) != (a)));
    assigns \nothing;
 */
bool func(long a, long b, long c)
{
    bool ans;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;
    
    ans = (a == b && b != c) || (a == c && c != b) || (b == c && c != a);
    
    //@ assert ans == true <==> (((a) == (b) && (b) != (c)) ||         ((a) == (c) && (c) != (b)) ||         ((b) == (c) && (c) != (a)));
    
    return ans;
}
