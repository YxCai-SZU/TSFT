#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result == ((a) + (b) + (c)) || \result == ((a) + (b) + (c)) + 1;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    //@ assert (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    //@ assert ((a) + (b) + (c)) <= 30;
    //@ assert ((a) + (b) + (c)) + 1 <= 31;

    result = a + b + c;

    if (a + b + c < 10)
    {
        result += 1;
    }

    //@ assert result == ((a) + (b) + (c)) || result == ((a) + (b) + (c)) + 1;
    return result;
}
