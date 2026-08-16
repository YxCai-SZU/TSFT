#include <limits.h>

/*@
    requires 0 <= a && a <= 23;
    requires 0 <= b && b <= 59;
    requires 0 <= c && c <= 23;
    requires 0 <= d && d <= 59;
    requires 0 <= e && e <= 10000;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c, int d, int e)
{
    int start_minutes;
    int end_minutes;
    int duration;
    int result;

    start_minutes = a * 60 + b;
    end_minutes = c * 60 + d;

    //@ assert start_minutes == a * 60 + b;
    //@ assert end_minutes == c * 60 + d;

    if (start_minutes > end_minutes) {
        duration = end_minutes + 24 * 60 - start_minutes;
    } else {
        duration = end_minutes - start_minutes;
    }

    //@ assert duration == (start_minutes > end_minutes ? end_minutes + 24 * 60 - start_minutes : end_minutes - start_minutes);

    if (duration <= e) {
        result = 0;
    } else {
        result = duration - e;
    }

    //@ assert result == (duration <= e ? 0 : duration - e);
    //@ assert result >= 0;

    return result;
}
