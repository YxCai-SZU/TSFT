#include <stdbool.h>

/*@
    requires (1 <= (x) <= 205 && 1 <= (y) <= 205);
    ensures \result == ((x) == 1 && (y) == 1 ? 1000000 :
        (x) == 1 && (y) != 1 ? 600000 - ((y) - 1) * 3000 :
        (x) != 1 && (y) == 1 ? 600000 - ((x) - 1) * 3000 :
        0);
    assigns \nothing;
*/
int func(int x, int y)
{
    //@ assert (1 <= (x) <= 205 && 1 <= (y) <= 205);
    
    if (x == 1 && y == 1)
    {
        //@ assert x == 1 && y == 1;
        return 1000000;
    }
    else if (x == 1)
    {
        //@ assert x == 1 && y != 1;
        return 600000 - (y - 1) * 3000;
    }
    else if (y == 1)
    {
        //@ assert x != 1 && y == 1;
        return 600000 - (x - 1) * 3000;
    }
    else
    {
        //@ assert x != 1 && y != 1;
        return 0;
    }
}

int main()
{
    return 0;
}
