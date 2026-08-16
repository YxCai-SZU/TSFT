#include <stdbool.h>

/*@
    requires 100 <= input <= 999;
    ensures \result == true <==> ((input) / 100 == 7 || ((input) / 10) % 10 == 7 || (input) % 10 == 7);
    assigns \nothing;
*/
bool func(unsigned int input)
{
    unsigned int A0;
    unsigned int A1;
    unsigned int A2;
    bool result;

    A0 = input / 100;
    A1 = (input / 10) % 10;
    A2 = input % 10;

    //@ assert A0 == input / 100;
    //@ assert A1 == (input / 10) % 10;
    //@ assert A2 == input % 10;

    result = (A0 == 7) || (A1 == 7) || (A2 == 7);
    return result;
}
