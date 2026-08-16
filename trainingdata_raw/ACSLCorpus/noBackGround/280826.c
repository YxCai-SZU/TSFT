#include <stdbool.h>

/*@
    requires 0 <= n <= 4294967295;
    ensures \result == true <==> n % 2 == 0;
    assigns \nothing;
*/
bool is_even(unsigned int n)
{
    //@ assert 0 <= n <= 4294967295;
    return n % 2 == 0;
}

int main()
{
    return 0;
}
