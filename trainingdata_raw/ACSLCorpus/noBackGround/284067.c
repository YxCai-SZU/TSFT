#include <stddef.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result == (((p) + (a) * 3) / 2);
    ensures \result <= p + a * 3;
    assigns \nothing;
*/
size_t func(size_t a, size_t p)
{
    size_t result;
    size_t tmp;

    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (p) && (p) <= 100);
    
    tmp = p + a * 3;
    //@ assert tmp == p + a * 3;
    
    result = tmp / 2;
    //@ assert result == (((p) + (a) * 3) / 2);
    
    return result;
}

int main()
{
    return 0;
}
