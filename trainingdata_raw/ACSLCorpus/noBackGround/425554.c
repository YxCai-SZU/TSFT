#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * 2 * 3);
    assigns \nothing;
*/
int func(int r)
{
    // Declare all variables at the top
    int pi;
    int result;
    int i;
    
    pi = 3;
    result = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= r;
        loop invariant result == ((i) * 2 * (pi));
        loop invariant pi == 3;
        loop invariant (1 <= (r) <= 100);
        loop assigns result, i;
        loop variant r - i;
    */
    while (i < r)
    {
        //@ assert pi == 3;
        result += 2 * pi;
        i += 1;
    }
    
    //@ assert result == ((r) * 2 * 3);
    return result;
}

int main(void)
{
    return 0;
}
