#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123);
    requires (0 <= (k) && (k) <= 123);
    ensures \result == ((((c) - (a) <= (k) ? 1 : 0) + ((c) - (b) <= (k) ? 1 : 0) + ((b) - (a) <= (k) ? 1 : 0) +
        ((e) - (c) <= (k) ? 1 : 0) + ((e) - (b) <= (k) ? 1 : 0) + ((e) - (a) <= (k) ? 1 : 0)) > 0);
*/
bool func(long long a, long long b, long long c, long long d, long long e, long long k)
{
    bool answer = false;

    //@ assert 0 <= c - a && c - a <= 123;
    if (c - a <= k)
    {
        answer = true;
    }

    //@ assert 0 <= c - b && c - b <= 123;
    if (c - b <= k)
    {
        answer = true;
    }

    //@ assert 0 <= b - a && b - a <= 123;
    if (b - a <= k)
    {
        answer = true;
    }

    //@ assert 0 <= e - c && e - c <= 123;
    if (e - c <= k)
    {
        answer = true;
    }

    //@ assert 0 <= e - b && e - b <= 123;
    if (e - b <= k)
    {
        answer = true;
    }

    //@ assert 0 <= e - a && e - a <= 123;
    if (e - a <= k)
    {
        answer = true;
    }

    return answer;
}
