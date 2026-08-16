#include <stdbool.h>

/*@
    requires (1 <= (a1) <= 13) && (1 <= (a2) <= 13) && (1 <= (a3) <= 13);
    ensures \result == true <==> a1 + a2 + a3 < 22;
    ensures \result == false <==> a1 + a2 + a3 >= 22;
*/
bool func(unsigned long a1, unsigned long a2, unsigned long a3)
{
    unsigned long total;
    bool result;

    total = a1 + a2 + a3;

    //@ assert total == ((a1) + (a2) + (a3));

    if (total >= 22)
    {
        //@ assert total >= 22;
        result = false;
    }
    else
    {
        //@ assert total < 22;
        result = true;
    }

    return result;
}
