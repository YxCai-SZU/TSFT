#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (((((a)) + ((b)) + ((c))) % 2 == 0) && (((a)) + ((b)) > ((c)) && ((b)) + ((c)) > ((a)) && ((c)) + ((a)) > ((b))));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result = false;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;

    if ((a + b + c) % 2 == 0)
    {
        //@ assert (((a) + (b) + (c)) % 2 == 0);
        if (a + b > c)
        {
            if (b + c > a)
            {
                if (c + a > b)
                {
                    result = true;
                    //@ assert ((a) + (b) > (c) && (b) + (c) > (a) && (c) + (a) > (b));
                }
            }
        }
    }

    //@ assert result == true <==> (((((a)) + ((b)) + ((c))) % 2 == 0) && (((a)) + ((b)) > ((c)) && ((b)) + ((c)) > ((a)) && ((c)) + ((a)) > ((b))));
    return result;
}
