#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    requires (1 <= (y) <= 100);
    ensures \result == (y >= 2 * x && y <= 4 * x && y % 2 == 0);
*/
bool func(unsigned int x, unsigned int y)
{
    bool flag = false;
    //@ assert (1 <= (x) <= 100);
    //@ assert (1 <= (y) <= 100);
    
    if (y >= 2 * x && y <= 4 * x)
    {
        if (y % 2 == 0)
        {
            flag = true;
        }
    }
    
    //@ assert flag == (y >= 2 * x && y <= 4 * x && y % 2 == 0);
    return flag;
}
