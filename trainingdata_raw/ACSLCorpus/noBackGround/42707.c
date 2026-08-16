#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (6 * (r));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t circumference;
    
    //@ assert 1 <= r <= 100;
    pi = 3;
    
    //@ assert pi == 3;
    circumference = 2 * pi * r;
    
    //@ assert 2 * pi >= 2 * 3;
    //@ assert 2 * pi <= 2 * 3;
    //@ assert 2 * pi * r >= 2 * 3 * 1;
    //@ assert 2 * pi * r <= 2 * 3 * 100;
    
    return circumference;
}

int main(void)
{
    return 0;
}
