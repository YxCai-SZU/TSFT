#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 10 &&
        0 <= (b) && (b) <= 10 &&
        0 <= (c) && (c) <= 10);
    ensures \result == true <==> (((a) == 5 && (b) == 5 && (c) == 7) ||
        ((a) == 5 && (b) == 7 && (c) == 5) ||
        ((a) == 7 && (b) == 5 && (c) == 5));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int m = 0;
    unsigned int n = 0;
    unsigned int tmp;

    tmp = a;
    //@ assert tmp == a;
    m += (tmp == 5) ? 1 : 0;
    tmp = b;
    //@ assert tmp == b;
    m += (tmp == 5) ? 1 : 0;
    tmp = c;
    //@ assert tmp == c;
    m += (tmp == 5) ? 1 : 0;

    tmp = a;
    //@ assert tmp == a;
    n += (tmp == 7) ? 1 : 0;
    tmp = b;
    //@ assert tmp == b;
    n += (tmp == 7) ? 1 : 0;
    tmp = c;
    //@ assert tmp == c;
    n += (tmp == 7) ? 1 : 0;

    //@ assert m == (((a) == 5 ? 1 : 0) +         ((b) == 5 ? 1 : 0) +         ((c) == 5 ? 1 : 0));
    //@ assert n == (((a) == 7 ? 1 : 0) +         ((b) == 7 ? 1 : 0) +         ((c) == 7 ? 1 : 0));
    //@ assert (m == 2 && n == 1) <==> (((a) == 5 && (b) == 5 && (c) == 7) ||         ((a) == 5 && (b) == 7 && (c) == 5) ||         ((a) == 7 && (b) == 5 && (c) == 5));

    return (m == 2 && n == 1);
}
