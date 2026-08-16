#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((a < c && b > c) || (a > c && b < c));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int i = 0;

    /*@
        loop invariant 0 <= i <= c;
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
        loop assigns i;
        loop variant c - i;
    */
    while (i < c)
    {
        i = i + 1;
    }

    return (a < c && b > c) || (a > c && b < c);
}
