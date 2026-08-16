#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result == ((((a) == (b) && (b) != (c)) ||
        ((b) == (c) && (c) != (a)) ||
        ((c) == (a) && (a) != (b)) ? 1 : 0) == 1);
*/
bool func(int a, int b, int c)
{
    bool result;

    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);
    
    //@ assert a == b || b == c || c == a || a != b || b != c || c != a;
    
    result = (a == b && b != c) || (b == c && c != a) || (c == a && a != b);
    
    //@ assert result == ((((a) == (b) && (b) != (c)) ||         ((b) == (c) && (c) != (a)) ||         ((c) == (a) && (a) != (b)) ? 1 : 0) == 1);
    
    return result;
}
