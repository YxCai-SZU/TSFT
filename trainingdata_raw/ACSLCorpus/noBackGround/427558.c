#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t answer;
    
    answer = a - 2 * b;
    
    //@ assert answer == a - 2 * b;
    
    if (answer > 0)
    {
        //@ assert answer >= 0;
        return answer;
    }
    else
    {
        //@ assert answer <= 0;
        //@ assert 0 >= 0;
        return 0;
    }
}
