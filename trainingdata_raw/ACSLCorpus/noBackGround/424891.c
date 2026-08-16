#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    result = a - b * 2;
    
    if (result > 0)
    {
        //@ assert result == a - b * 2 || result == 0;
        return result;
    }
    else
    {
        //@ assert result == a - b * 2 || result == 0;
        return 0;
    }
}
