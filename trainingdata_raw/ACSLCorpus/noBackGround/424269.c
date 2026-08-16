#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) - ((b) * 2)) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int answer;
    int result;

    answer = a - (b * 2);

    //@ assert answer == ((a) - ((b) * 2));
    //@ assert answer >= 0 || answer < 0;

    if (answer > 0)
    {
        //@ assert answer == ((a) - ((b) * 2));
        result = answer;
    }
    else
    {
        //@ assert 0 == 0;
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result == ((a) - ((b) * 2)) || result == 0;
    return result;
}
