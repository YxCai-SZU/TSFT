#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    requires (1 <= (b) && (b) <= 100);
    requires (1 <= (c) && (c) <= 100);
    ensures \result == true <==> ((a) == (b) + (c) || (b) == (a) + (c) || (c) == (a) + (b));
*/
bool func(int a, int b, int c)
{
    bool result;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);

    result = (a == b + c) || (b == a + c) || (c == a + b);
    
    //@ assert result == true <==> ((a) == (b) + (c) || (b) == (a) + (c) || (c) == (a) + (b));
    return result;
}
