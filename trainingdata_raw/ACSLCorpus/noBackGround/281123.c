#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
*/
long long func(unsigned long long a, unsigned long long b)
{
    unsigned long long sum;
    unsigned long long half_sum;
    long long result;

    sum = a + b;
    half_sum = sum / 2;
    if (sum % 2 != 0) {
        result = (long long)(half_sum + 1);
    } else {
        result = (long long)half_sum;
    }

    //@ assert result == (((a) + (b) + 1) / 2);
    return result;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100) && (1 <= (e) <= 100);
    requires (1 <= (k) <= 123);
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
*/
bool check_maximum(unsigned long long a, unsigned long long b, unsigned long long c,
                   unsigned long long d, unsigned long long e, unsigned long long k)
{
    unsigned long long dist;
    bool result;

    dist = e - a;
    //@ assert dist == e - a;
    result = dist <= k;

    //@ assert result == (e - a <= k);
    return result;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100) && (1 <= (e) <= 100);
    requires (1 <= (k) <= 123);
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (((e) - (a) <= (k)) ? 0 : ((e) - (a) - (k)));
*/
long long func2(long long a, long long b, long long c, long long d, long long e, long long k)
{
    long long dist;
    long long result;

    dist = e - a;
    if (dist <= k) {
        result = 0;
    } else {
        result = dist - k;
    }

    //@ assert result == (((e) - (a) <= (k)) ? 0 : ((e) - (a) - (k)));
    return result;
}
