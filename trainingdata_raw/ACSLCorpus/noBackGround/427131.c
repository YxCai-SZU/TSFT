#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires ((3) == 3 &&
        1 <= (v)[0] <= 20 &&
        1 <= (v)[1] <= 20 &&
        1 <= (v)[2] <= 20);
    ensures \result >= 0;
    ensures \result <= v[0] + v[1] || \result <= v[0] + v[2] || \result <= v[1] + v[2];
    assigns \nothing;
*/
int func(int *v)
{
    int result;
    int temp_result;
    
    //@ assert ((3) == 3 &&         1 <= (v)[0] <= 20 &&         1 <= (v)[1] <= 20 &&         1 <= (v)[2] <= 20);
    
    result = v[0] + v[1];
    //@ assert result >= 0;
    
    temp_result = v[0] + v[2];
    //@ assert temp_result >= 0;
    
    if (temp_result < result)
    {
        result = temp_result;
    }
    //@ assert result >= 0;
    
    temp_result = v[1] + v[2];
    //@ assert temp_result >= 0;
    
    if (temp_result < result)
    {
        result = temp_result;
    }
    //@ assert result >= 0;
    
    //@ assert result <= v[0] + v[1] || result <= v[0] + v[2] || result <= v[1] + v[2];
    
    return result;
}
