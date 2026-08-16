#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result == true <==> (((a) == (b) && (a) != (c)) || ((b) == (c) && (b) != (a)) || ((c) == (a) && (c) != (b)));
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int ab;
    unsigned int bc;
    unsigned int ca;
    bool result;

    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);

    ab = a > b ? a - b : b - a;
    bc = b > c ? b - c : c - b;
    ca = c > a ? c - a : a - c;

    //@ assert 0 <= ab <= 8;
    //@ assert 0 <= bc <= 8;
    //@ assert 0 <= ca <= 8;

    result = (ab == 0 && bc != 0 && ca != 0) ||
             (bc == 0 && ca != 0 && ab != 0) ||
             (ca == 0 && ab != 0 && bc != 0);

    //@ assert result == true <==> (((a) == (b) && (a) != (c)) || ((b) == (c) && (b) != (a)) || ((c) == (a) && (c) != (b)));
    return result;
}
