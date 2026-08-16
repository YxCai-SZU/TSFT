#include <stdbool.h>


bool func(int a, int b, int c, int d)
{
    bool result;

    //@ assert d < a || c < b ==> (d < a || c < b);
    //@ assert !(d < a || c < b) ==> !(d < a || c < b);

    if (d < a || c < b) {
        result = true;
    } else {
        result = false;
    }

    //@ assert ((result) == ((d) < (a) || (c) < (b)));
    return result;
}
