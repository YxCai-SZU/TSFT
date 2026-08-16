#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min;
    int answer;

    min = a;
    //@ assert min == a;
    //@ assert (1 <= (min) <= 100);

    if (b < min)
    {
        min = b;
        //@ assert min == b;
    }
    //@ assert min <= a && min <= b;
    //@ assert (1 <= (min) <= 100);

    if (c < min)
    {
        min = c;
        //@ assert min == c;
    }
    //@ assert min <= a && min <= b && min <= c;
    //@ assert (1 <= (min) <= 100);

    //@ assert min >= 1 && min <= 100;
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 100;

    answer = 0;
    answer += (a == min) ? 1 : 0;
    //@ assert answer >= 0 && answer <= 1;

    answer += (b == min) ? 1 : 0;
    //@ assert answer >= 0 && answer <= 2;

    answer += (c == min) ? 1 : 0;
    //@ assert answer >= 1 && answer <= 3;

    return answer;
}
