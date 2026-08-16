#include <stdbool.h>

/*@
    requires (10 <= (a) && (a) <= 99);
    ensures \result == (((a) / 10) == 9 || ((a) % 10) == 9);
*/
bool func(int a)
{
    int a_10;
    int a_1;

    //@ assert (10 <= (a) && (a) <= 99);
    //@ assert ((a) / 10) == a / 10;
    //@ assert ((a) % 10) == a % 10;

    a_10 = a / 10;
    a_1 = a % 10;

    //@ assert a_10 == ((a) / 10);
    //@ assert a_1 == ((a) % 10);

    return a_10 == 9 || a_1 == 9;
}
