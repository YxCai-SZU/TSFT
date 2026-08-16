#include <stdbool.h>

/*@
    requires 100 <= a <= 999;
    ensures \result == true <==> ((a) / 100 == 7 || ((a) / 10) % 10 == 7 || (a) % 10 == 7);
    assigns \nothing;
*/
bool func(unsigned int a)
{
    unsigned int a_100;
    unsigned int a_10;
    unsigned int a_1;
    unsigned int a_10_mod;
    bool result;

    a_100 = a / 100;
    a_10 = a / 10;
    a_1 = a % 10;
    a_10_mod = a_10 % 10;

    //@ assert a_100 == a / 100;
    //@ assert a_10_mod == (a / 10) % 10;
    //@ assert a_1 == a % 10;

    result = (a_100 == 7 || a_10_mod == 7 || a_1 == 7);
    return result;
}
