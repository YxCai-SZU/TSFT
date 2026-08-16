#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 9) && (1 <= (b) && (b) <= 9) && (1 <= (c) && (c) <= 9);
    ensures \result == ((((a) == (b) && (b) != (c)) || ((b) == (c) && (b) != (a)) || ((c) == (a) && (c) != (b)) ? 1 : 0) == 1);
*/
bool func(int a, int b, int c)
{
    bool ab;
    bool bc;
    bool ca;
    bool x;
    bool y;
    bool z;
    bool result;
    
    //@ assert (1 <= (a) && (a) <= 9);
    ab = (a == b);
    bc = (b == c);
    ca = (c == a);
    x = (ab && !bc);
    y = (bc && !ca);
    z = (ca && !ab);
    result = (x || y || z);
    
    //@ assert result == ((((a) == (b) && (b) != (c)) || ((b) == (c) && (b) != (a)) || ((c) == (a) && (c) != (b)) ? 1 : 0) == 1);
    return result;
}
