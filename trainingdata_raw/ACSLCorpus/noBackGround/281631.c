#include <stdbool.h>

/*@ requires 1 <= r <= 100;
    ensures \result == 2 * r * 3 || \result == 2 * r * 3 - 1;
    ensures \result > 0;
    assigns \nothing;
 */
int func(int r)
{
    int pi = 3;
    int result = 2 * r * pi;
    unsigned int n = (unsigned int)result;

    /*@ loop invariant 0 <= n <= (unsigned int)(2 * r * pi);
        loop assigns n;
        loop variant n;
     */
    while (n >= 2)
    {
        n = n - 2;
    }

    //@ assert n == 0 || n == 1;
    
    if (n == 1)
    {
        result = result - 1;
        //@ assert result == 2 * r * 3 - 1;
    }
    else
    {
        //@ assert result == 2 * r * 3;
    }

    return result;
}

int main()
{
    return 0;
}
