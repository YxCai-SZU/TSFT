#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 2 * 3);
    assigns \nothing;
*/
int func(int n)
{
    int pi_approx = 3;
    int circumference;
    int i = 0;

    circumference = n * 2 * pi_approx;

    /*@
        loop invariant (0 <= (i) && (i) <= (n));
        loop assigns i;
        loop variant n - i;
    */
    while (i < n)
    {
        i = i + 1;
    }

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert (0 <= (i) && (i) <= (n));
    //@ assert circumference == ((n) * 2 * 3);

    return circumference;
}
