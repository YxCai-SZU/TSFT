#include <stdbool.h>

/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == ((g * 10 + b) % 4 == 0);
    assigns \nothing;
*/
bool func(int r, int g, int b)
{
    //@ assert (1 <= (r) <= 9);
    //@ assert (1 <= (g) <= 9);
    //@ assert (1 <= (b) <= 9);
    return (g * 10 + b) % 4 == 0;
}

/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == ((r * 10 + g) % 4 == 0);
    assigns \nothing;
*/
bool func2(int r, int g, int b)
{
    //@ assert (1 <= (r) <= 9);
    //@ assert (1 <= (g) <= 9);
    //@ assert (1 <= (b) <= 9);
    return (r * 10 + g) % 4 == 0;
}

/*@
    requires (1 <= (r) <= 9) && (1 <= (g) <= 9) && (1 <= (b) <= 9);
    ensures \result == ((b * 10 + r) % 4 == 0);
    assigns \nothing;
*/
bool func3(int r, int g, int b)
{
    //@ assert (1 <= (r) <= 9);
    //@ assert (1 <= (g) <= 9);
    //@ assert (1 <= (b) <= 9);
    return (b * 10 + r) % 4 == 0;
}
