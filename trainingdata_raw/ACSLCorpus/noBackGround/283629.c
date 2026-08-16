#include <stdbool.h>

/*@
    requires 0 <= a && a < 10;
    ensures \result == (a % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a)
{
    //@ assert a % 2 == a % 2;
    return a % 2 == 0;
}

int main()
{
    return 0;
}
