#include <stdint.h>

/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t ans;
    
    //@ assert (1 <= (k) <= (n) <= 50);
    //@ assert ((n) - (k) + 1) >= 1;
    //@ assert ((n) - (k) + 1) <= 50;
    
    ans = n - k + 1;
    
    //@ assert ans == ((n) - (k) + 1);
    return ans;
}

int main()
{
    return 0;
}
