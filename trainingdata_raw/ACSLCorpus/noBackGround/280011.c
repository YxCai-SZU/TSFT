#include <stdbool.h>

/*@
    requires -40 <= X <= 40;
    ensures \result <==> ((X) >= 30);
    assigns \nothing;
*/
bool func(int X)
{
    bool air_conditioner_on;
    
    //@ assert -40 <= X <= 40;
    
    if (X >= 30)
    {
        //@ assert X >= 30;
        air_conditioner_on = true;
    }
    else
    {
        //@ assert X < 30;
        air_conditioner_on = false;
    }
    
    //@ assert air_conditioner_on <==> ((X) >= 30);
    return air_conditioner_on;
}
