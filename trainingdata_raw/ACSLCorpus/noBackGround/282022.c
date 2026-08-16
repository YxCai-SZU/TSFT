#include <stdbool.h>

/*@
    requires \valid_read(v + (0..2));
    requires (1 <= (v[0]) <= 10) && (1 <= (v[1]) <= 10) && (1 <= (v[2]) <= 10);
    ensures \result == true <==> ((((v[1])) - ((v[0]))) == (((v[2])) - ((v[1]))));
    assigns \nothing;
*/
bool func(const int *v)
{
    int a;
    int b;
    int c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    //@ assert ((b) - (a)) >= -9 && ((b) - (a)) <= 9;

    result = (b - a) == (c - b);
    //@ assert result == true <==> ((((b)) - ((a))) == (((c)) - ((b))));
    return result;
}
