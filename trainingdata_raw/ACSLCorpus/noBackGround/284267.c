#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 9) && (1 <= (g) && (g) <= 9) && (1 <= (b) && (b) <= 9);
    ensures \result == ((100 * (r) + 10 * (g) + (b)) % 4 == 0);
*/
bool func(unsigned int r, unsigned int g, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int temp1;
    unsigned int temp2;
    unsigned int temp3;
    unsigned int temp4;
    bool result;

    //@ assert 100 * r <= 900;
    temp1 = 100 * r;

    //@ assert 10 * g <= 90;
    temp2 = 10 * g;

    //@ assert temp1 + temp2 <= 990;
    temp3 = temp1 + temp2;

    //@ assert temp3 + b <= 999;
    temp4 = temp3 + b;

    result = (temp4 % 4 == 0);
    return result;
}
