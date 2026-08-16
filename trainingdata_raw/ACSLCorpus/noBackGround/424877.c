#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a * 2;
    ensures \result == (a * 2 - b) || \result == 0;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    int32_t answer;
    answer = a * 2 - b;
    //@ assert answer == a * 2 - b;
    if (answer > 0)
    {
        //@ assert answer > 0;
        return answer;
    }
    else
    {
        //@ assert answer <= 0;
        return 0;
    }
}
