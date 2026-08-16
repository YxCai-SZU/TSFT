#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == true <==> ((n / k) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int k)
{
    unsigned int is_even;
    bool result;

    //@ assert k != 0;
    is_even = (n / k) % 2;
    
    //@ assert is_even == (n / k % 2);
    
    result = (is_even == 0);
    //@ assert result == true <==> ((n / k) % 2 == 0);
    return result;
}

int main()
{
    return 0;
}
