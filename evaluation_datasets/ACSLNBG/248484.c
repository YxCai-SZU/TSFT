#include <stdbool.h>


bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= b;
    //@ assert (-100 <= (c) <= 100);
    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    //@ assert c >= a && c <= b ==> (-100 <= (c) <= 100);

    result = (c >= a && c <= b);
    return result;
}
