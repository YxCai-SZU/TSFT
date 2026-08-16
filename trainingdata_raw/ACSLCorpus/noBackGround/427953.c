#include <stdbool.h>

/*@ requires (1 <= (a) && (a) <= 100 &&
    1 <= (b) && (b) <= 100 &&
    1 <= (c) && (c) <= 100);
    ensures \result == true <==> (a == b + c || b == c + a || c == a + b);
*/
bool func(long a, long b, long c)
{
    long d = a;
    long e = b;
    long f = c;
    long temp;

    //@ assert d == a && e == b && f == c;

    if (d < e)
    {
        temp = d;
        d = e;
        e = temp;
    }
    //@ assert d >= e;

    if (e < f)
    {
        temp = e;
        e = f;
        f = temp;
    }
    //@ assert e >= f;

    if (d < e)
    {
        temp = d;
        d = e;
        e = temp;
    }
    //@ assert d >= e && e >= f;

    //@ assert d == (((a) >= (b) && (a) >= (c)) ? (a) :     ((b) >= (a) && (b) >= (c)) ? (b) : (c));
    //@ assert e == (((a) >= (b) && (a) <= (c)) || ((a) <= (b) && (a) >= (c)) ? (a) :     ((b) >= (a) && (b) <= (c)) || ((b) <= (a) && (b) >= (c)) ? (b) : (c));
    //@ assert f == (((a) <= (b) && (a) <= (c)) ? (a) :     ((b) <= (a) && (b) <= (c)) ? (b) : (c));

    if (d == e + f)
    {
        return true;
    }
    else
    {
        return false;
    }
}
