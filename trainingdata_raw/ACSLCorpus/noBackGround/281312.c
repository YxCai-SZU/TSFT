#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    ensures ((\result) + (a) + (b) == 6 &&
        1 <= (\result) && (\result) <= 3);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    int answer;

    result = 6 - a - b;

    //@ assert result == (6 - (a) - (b));
    //@ assert result + a + b == 6;

    if (result == 1) {
        answer = 1;
    } else if (result == 2) {
        answer = 2;
    } else {
        answer = 3;
    }

    //@ assert 1 <= answer && answer <= 3;
    //@ assert answer + a + b == 6;

    return answer;
}
