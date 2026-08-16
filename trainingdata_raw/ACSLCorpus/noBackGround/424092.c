#include <stdbool.h>

/*@
    requires -40 <= x && x <= 40;
    ensures \result <==> ((x) >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    bool air_conditioner_on;
    
    //@ assert -40 <= x && x <= 40;
    
    if (x >= 30) {
        //@ assert ((x) >= 30);
        air_conditioner_on = true;
    } else {
        //@ assert !((x) >= 30);
        air_conditioner_on = false;
    }
    
    //@ assert air_conditioner_on <==> ((x) >= 30);
    return air_conditioner_on;
}
