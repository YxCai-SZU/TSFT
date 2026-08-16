#include <stdint.h>

/*@
    requires ((0) <= (x) && (x) <= (9)) && ((0) <= (a) && (a) <= (9));
    ensures (x < a ==> \result == 0) && (x >= a ==> \result == 10);
*/
int64_t func(int64_t x, int64_t a)
{
    //@ assert ((0) <= (x) && (x) <= (9));
    //@ assert ((0) <= (a) && (a) <= (9));
    int64_t res;
    if (x < a) {
        res = 0;
    } else {
        res = 10;
    }
    //@ assert (x < a ==> res == 0) && (x >= a ==> res == 10);
    return res;
}

/*@
    requires ((1) <= (x) && (x) <= (9));
    ensures \result == ((x) * (x) * (x));
*/
int64_t func2(int64_t x)
{
    //@ assert ((1) <= (x) && (x) <= (9));
    //@ assert ((1) <= (x * x) && (x * x) <= (81));
    //@ assert ((1) <= (x * x * x) && (x * x * x) <= (729));
    int64_t res = x * x * x;
    //@ assert res == ((x) * (x) * (x));
    return res;
}

/*@
    requires ((1) <= (x) && (x) <= (100));
    ensures \result == ((x) * (x));
*/
int64_t func3(int64_t x)
{
    //@ assert ((1) <= (x) && (x) <= (100));
    //@ assert ((1) <= (x * x) && (x * x) <= (10000));
    int64_t res = x * x;
    //@ assert res == ((x) * (x));
    return res;
}
