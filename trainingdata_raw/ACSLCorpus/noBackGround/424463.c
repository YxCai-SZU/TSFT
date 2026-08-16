#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ( (a * 100 + b * 10 + c) % 4 == 0 );
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    unsigned int a100;
    unsigned int b10;
    unsigned int total;
    bool result;

    a100 = a * 100;
    b10 = b * 10;

    //@ assert a100 <= 900;
    //@ assert b10 <= 90;

    total = a100 + b10 + c;
    //@ assert total <= 999;

    result = (total % 4 == 0);
    return result;
}

int main()
{
    return 0;
}
