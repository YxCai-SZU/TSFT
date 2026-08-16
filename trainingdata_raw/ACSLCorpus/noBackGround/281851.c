#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000000000000 &&
        1 <= (k) <= (n) + 1);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t ans;
    
    //@ assert 1 <= n && n <= 1000000000000000000;
    //@ assert 1 <= k && k <= n + 1;
    //@ assert n - k + 1 >= 0;
    //@ assert n - k + 1 <= 1000000000000000000;
    
    ans = n - k + 1;
    return ans;
}

int main()
{
    return 0;
}
