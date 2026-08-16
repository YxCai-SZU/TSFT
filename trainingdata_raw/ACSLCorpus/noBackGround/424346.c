#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (b) != (c)) ||
        ((a) == (c) && (c) != (b)) ||
        ((b) == (c) && (a) != (b)));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;
    
    result = (a == b && a != c) || (a == c && a != b) || (b == c && b != a);
    
    //@ assert result == true <==> (((a) == (b) && (b) != (c)) ||         ((a) == (c) && (c) != (b)) ||         ((b) == (c) && (a) != (b)));
    return result;
}
