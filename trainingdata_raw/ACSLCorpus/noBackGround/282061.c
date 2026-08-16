#include <stdbool.h>

/*@
    requires a == b;
    ensures \result == true;
    assigns \nothing;
*/
bool check_bitwise_eq(unsigned int a, unsigned int b)
{
    //@ assert (((a) & 3) == ((b) & 3));
    return true;
}

int main()
{
    return 0;
}
