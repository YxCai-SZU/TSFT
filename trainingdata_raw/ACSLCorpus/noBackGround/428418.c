#include <stdbool.h>

/*@
    requires 1 <= N <= 10000;
    requires 1 <= N_ <= 10000;
    requires 1 <= A <= 10000;
    ensures \result == (N - N_ >= A);
*/
bool func(int N, int N_, int A)
{
    int diff;
    bool result;

    //@ assert (-10000 <= (N) - (N_) <= 10000);
    //@ assert N - N_ >= -10000;
    //@ assert N - N_ <= 10000;

    diff = N - N_;
    result = (diff >= A) ? true : false;

    //@ assert ((result) == ((N) - (N_) >= (A)));
    return result;
}
