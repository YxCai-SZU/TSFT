#include <stdint.h>

/*@
    requires 1 <= a && a <= 100;
    requires a == (long long)(integer)a;
    ensures \result == (2 * 3141592 * a) / 1000000;
*/
long long func(long long a)
{
    // Variable declarations at top of scope
    long long pi = 3141592;
    long long two = 2;
    long long scale = 1000000;
    long long result = 0;
    long long temp_a = 0;
    long long count = 0;

    //@ assert pi == (3141592);
    //@ assert (2)== 2;
    //@ assert scale == (1000000);

    temp_a = a * two * pi;
    //@ assert temp_a == a * (2)* (3141592);

    //@ assert 2 * (3141592)* a == 2 * 3141592 * a;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant pi == 3141592;
        loop invariant (2)== 2;
        loop invariant scale == 1000000;
        loop invariant temp_a >= 0;
        loop invariant temp_a == a * (2)* pi - count * scale;
        loop invariant count >= 0;
        loop invariant count <= (a * (2)* pi) / scale;
        loop invariant a == (long long)(integer)a;
        loop invariant count * scale <= a * (2)* pi;
        loop assigns temp_a, count;
    */
    while (temp_a >= scale) {
        temp_a -= scale;
        count += 1;
    }
    result = count;

    //@ assert temp_a >= 0;
    //@ assert temp_a < scale;
    //@ assert result * scale + temp_a == a * (2)* pi;
    //@ assert result == (a * (2)* pi) / scale;

    //@ assert result == (2 * 3141592 * a) / 1000000;
    return result;
}
