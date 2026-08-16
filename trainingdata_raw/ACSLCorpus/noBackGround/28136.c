#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= x <= 100;
    ensures \result == true <==> ((b) <= (x) && (x) <= (a) + (b));
*/
bool is_possible_x_cats(int a, int b, int x)
{
    bool result;
    //@ assert 0 <= a <= 100 && 0 <= b <= 100 && 0 <= x <= 100;
    
    if (b > x || x > a + b)
    {
        //@ assert b > x || x > a + b;
        result = false;
    }
    else
    {
        //@ assert b <= x && x <= a + b;
        result = true;
    }
    
    //@ assert result == true <==> ((b) <= (x) && (x) <= (a) + (b));
    return result;
}
