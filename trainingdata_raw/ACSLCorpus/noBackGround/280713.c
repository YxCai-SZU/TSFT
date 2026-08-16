#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result >= 0;
    ensures \result == n - k || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert n >= 1 && n <= 100;
    //@ assert k >= 1 && k <= 100;
    
    if (n - k > 0) {
        result = n - k;
    } else {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == n - k || result == 0;
    
    return result;
}

int main(void)
{
    return 0;
}
