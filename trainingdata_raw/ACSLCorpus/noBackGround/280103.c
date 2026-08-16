#include <stddef.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <= c;
    ensures \result <= b / a;
    ensures \result == c || \result == b / a;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    result = b / a;
    
    if (result < c) {
        return result;
    } else {
        //@ assert result >= c;
        return c;
    }
}

int main(void)
{
    return 0;
}
