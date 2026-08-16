#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == ((a == b && c == a) || (a != b && a != c && b != c));
*/
bool func(int a, int b, int c)
{
    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;
    
    bool result;
    result = (a == b && c == a) || (a != b && a != c && b != c);
    
    //@ assert result == ((a == b && c == a) || (a != b && a != c && b != c));
    return result;
}
