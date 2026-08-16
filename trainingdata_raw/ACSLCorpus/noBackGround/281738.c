#include <stdbool.h>

/*@
    requires 10 <= a && a <= 99;
    ensures \result == (a / 10 == 7 || a / 10 == 5 || a / 10 == 3 || 
                       a % 10 == 7 || a % 10 == 5 || a % 10 == 3);
    ensures (((\result) == (((a) / 10 == 7) || ((a) / 10 == 5) || ((a) / 10 == 3) || 
                   ((a) % 10 == 7) || ((a) % 10 == 5) || ((a) % 10 == 3))) ? 1 : 0) == 1;
*/
bool func(unsigned int a)
{
    unsigned int n1;
    unsigned int n2;
    bool result;

    n1 = a / 10;
    n2 = a % 10;

    //@ assert n1 == a / 10;
    //@ assert n2 == a % 10;

    result = (n1 == 7 || n1 == 5 || n1 == 3 || n2 == 7 || n2 == 5 || n2 == 3);
    return result;
}
