#include <limits.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert (1*1 <= (r * r) && (r * r) <= 100*100);
    return r * r;
}

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == a * b;
    assigns \nothing;
*/
int input_int_tuple(int a, int b)
{
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1*1 <= (a * b) && (a * b) <= 100*100);
    return a * b;
}

/*@
    requires (1 <= (r) && (r) <= 100) && (1 <= (g) && (g) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == (r * 100 + g * 10 + b);
    assigns \nothing;
*/
int input_int(int r, int g, int b)
{
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert (1 <= (g) && (g) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1*100 + 1*10 + 1 <= (r * 100 + g * 10 + b) && (r * 100 + g * 10 + b) <= 100*100 + 100*10 + 100);
    return r * 100 + g * 10 + b;
}
