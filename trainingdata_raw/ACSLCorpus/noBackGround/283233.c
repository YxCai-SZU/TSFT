#include <stdbool.h>

/*@
    requires \true;
    assigns \nothing;
    ensures \result == (n % 2 == 0);
*/
bool is_even(unsigned int n)
{
    //@ assert n % 2 == 0 ==> n % 2 == 0;
    return n % 2 == 0;
}

int main()
{
    return 0;
}
