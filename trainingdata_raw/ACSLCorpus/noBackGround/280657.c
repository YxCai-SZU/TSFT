#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 10);
    ensures \result == ((n) + (n) * (n) + (n) * (n) * (n));
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    int32_t result;
    int32_t n_squared;
    int32_t n_cubed;
    
    //@ assert (1 <= (n) && (n) <= 10);
    
    //@ assert 1 <= n * n && n * n <= 100;
    n_squared = n * n;
    
    //@ assert 1 <= n * n * n && n * n * n <= 1000;
    n_cubed = n * n * n;
    
    result = n;
    result += n_squared;
    result += n_cubed;
    
    //@ assert result == ((n) + (n) * (n) + (n) * (n) * (n));
    return result;
}

int main()
{
    return 0;
}
