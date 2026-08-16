#include <stdint.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    requires A == (int64_t)A && B == (int64_t)B;
    ensures \result == A - (B * 2) || \result == 0;
    ensures \result >= 0;
*/
int64_t func(int64_t A, int64_t B)
{
    int64_t answer;
    answer = A - (B * 2);
    
    //@ assert answer == A - (B * 2);
    
    if (answer > 0)
    {
        //@ assert answer == A - (B * 2);
        return answer;
    }
    else
    {
        //@ assert 0 >= 0;
        return 0;
    }
}
