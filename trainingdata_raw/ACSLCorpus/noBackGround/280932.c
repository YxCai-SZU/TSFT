#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures (n == 9 && m == 5) ==> \result == 0;
    ensures (n != 9 || m != 5) ==> \result == ((n) * (m));
    assigns \nothing;
*/
int func(int n, int m)
{
    // Declare all variables at the top
    int result;

    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);

    if (n == 9 && m == 5)
    {
        result = 0;
    }
    else
    {
        //@ assert 1 <= n && n <= 20;
        //@ assert 1 <= m && m <= 20;
        //@ assert 1 <= ((n) * (m)) && ((n) * (m)) <= 400;
        result = n * m;
    }

    return result;
}
