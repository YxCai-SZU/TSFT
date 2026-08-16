#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == ((a == b && a != c) || (b == c && b != a) || (a == c && a != b));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool same_and_diff;
    
    same_and_diff = (a == b && a != c) || (b == c && b != a) || (a == c && a != b);
    
    //@ assert same_and_diff == ((a == b && a != c) || (b == c && b != a) || (a == c && a != b));
    
    return same_and_diff;
}
