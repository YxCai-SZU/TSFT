#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9);
    requires (1 <= (g) <= 9);
    requires (1 <= (b) <= 9);
    ensures ((\result) == (((((g)) * 10 + ((b))) % 4 == 0) || ((b) % 4 == 0) || ((((r)) * 10 + ((g))) % 4 == 0)));
*/
bool func(unsigned int r, unsigned int g, unsigned int b)
{
    unsigned int sum1;
    unsigned int sum2;
    bool result1;
    bool result2;
    bool result3;
    bool result;

    sum1 = g * 10 + b;
    sum2 = r * 10 + g;

    result1 = (sum1 % 4 == 0);
    result2 = (b % 4 == 0);
    result3 = (sum2 % 4 == 0);

    //@ assert result1 == (sum1 % 4 == 0);
    //@ assert result2 == (b % 4 == 0);
    //@ assert result3 == (sum2 % 4 == 0);

    result = result1 || result2 || result3;
    return result;
}
