#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(unsigned int a, unsigned int b)
{
    bool result;
    unsigned int tmp;

    if (a % 3 == 0)
    {
        result = true;
        tmp = 0;
    }
    else if (b % 3 == 0)
    {
        result = true;
        tmp = 0;
    }
    else if ((a + b) % 3 == 0)
    {
        result = true;
        tmp = 0;
    }
    else
    {
        result = false;
        tmp = 0;
    }

    //@ assert result == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);

    return result;
}
