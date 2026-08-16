#include <stdbool.h>

/*@
    requires (\valid((numbers)) &&
        (numbers)[0] >= 1 && (numbers)[0] <= 20 &&
        (numbers)[1] >= 1 && (numbers)[1] <= 20 &&
        (numbers)[2] >= 1 && (numbers)[2] <= 20);
    ensures \result >= 0 && \result <= 3;
    assigns \nothing;
*/
int func(int *numbers)
{
    int res;
    res = 0;
    
    //@ assert numbers[0] >= 1 && numbers[0] <= 20;
    //@ assert numbers[1] >= 1 && numbers[1] <= 20;
    //@ assert numbers[2] >= 1 && numbers[2] <= 20;
    
    if (numbers[0] < numbers[1] && numbers[1] < numbers[2])
    {
        res = 1;
    }
    else if (numbers[0] == numbers[1] && numbers[1] == numbers[2])
    {
        res = 3;
    }
    
    //@ assert res >= 0 && res <= 3;
    return res;
}
