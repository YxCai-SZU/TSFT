#include <stdbool.h>

/*@ predicate sorted(integer x, integer y, integer z) = x <= y && y <= z; */

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures \result == ((a == 5 && b == 5 && c == 7) || 
                        (a == 5 && b == 7 && c == 5) || 
                        (a == 7 && b == 5 && c == 5));
*/
bool func(int a, int b, int c)
{
    int x;
    int y;
    int z;
    int temp;
    
    x = a;
    y = b;
    z = c;
    
    //@ assert 1 <= x <= 10 && 1 <= y <= 10 && 1 <= z <= 10;
    
    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    
    if (y > z)
    {
        temp = y;
        y = z;
        z = temp;
    }
    
    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    
    //@ assert sorted(x, y, z);
    
    return (x == 5 && y == 5 && z == 7);
}
