#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    ensures \result == ((500 * (k)) >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    //@ assert (500 * (k)) <= 100000;
    return 500 * k >= x;
}

/*@
    requires (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    ensures \result == ((500 * (k)) >= x);
    assigns \nothing;
*/
bool func_subtraction(unsigned int k, unsigned int x)
{
    //@ assert (500 * (k)) <= 100000;
    return 500 * k >= x;
}

/*@
    requires (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    ensures \result == ((500 * (k)) >= x);
    assigns \nothing;
*/
bool func_addition(unsigned int k, unsigned int x)
{
    //@ assert (500 * (k)) <= 100000;
    return 500 * k >= x;
}
