#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    return a < b && b < c;
}

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result == (a <= b && b <= c);
    assigns \nothing;
*/
bool func2(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    return a <= b && b <= c;
}

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result == (a <= b && b == c);
    assigns \nothing;
*/
bool func3(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    return a <= b && b == c;
}

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result == (a < b && b == c);
    assigns \nothing;
*/
bool func4(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    return a < b && b == c;
}
