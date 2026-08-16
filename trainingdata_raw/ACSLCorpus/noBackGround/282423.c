#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == (a * 2 <= b);
    assigns \nothing;
*/
bool func(int a, int b)
{
    int double_a;
    bool result;
    
    //@ assert ((a) * 2) <= 200;
    
    double_a = a * 2;
    
    if (b >= double_a)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert result == (a * 2 <= b);
    
    return result;
}
