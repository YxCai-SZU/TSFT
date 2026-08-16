#include <limits.h>

/*@
    requires (0 <= (a) <= 1000000000 &&
        0 <= (b) <= 1000000000 &&
        (a) * (b) <= INT_MAX);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int answer;
    //@ assert (0 <= (a) <= 1000000000 &&         0 <= (b) <= 1000000000 &&         (a) * (b) <= INT_MAX);
    answer = a * b;
    //@ assert answer == ((a) * (b));
    return answer;
}
