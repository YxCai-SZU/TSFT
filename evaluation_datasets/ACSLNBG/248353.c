#include <limits.h>


int func(int x, int y, int z)
{
    int result = 0;
    int numerator = x - z;
    int denominator = y + z;

    
    while (numerator >= denominator)
    {
        //@ assert numerator >= denominator;
        //@ assert result <= x;

        numerator -= denominator;
        result += 1;
    }

    return result;
}
