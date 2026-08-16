#include <stdint.h>

/*@ requires (1 <= (r) <= 100);
    ensures \result == ((r) * 2 * 3);
    assigns \nothing;
 */
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi;
    int64_t result;
    
    pi = 3;
    result = r * 2 * pi;
    
    //@ assert result == r * 2 * 3;
    
    return result;
}

int main(void)
{
    return 0;
}
