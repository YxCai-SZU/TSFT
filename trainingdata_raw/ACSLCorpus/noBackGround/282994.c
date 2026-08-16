#include <stdbool.h>

/*@
    requires (100 <= (a) && (a) <= 999);
    ensures \result == (((a) / 100) == 7 || (((a) / 10) % 10) == 7 || ((a) % 10) == 7);
    assigns \nothing;
*/
bool func(int a)
{
    // Variable declarations at top of scope
    int hundreds;
    int tens;
    int units;
    bool result;

    //@ assert (100 <= (a) && (a) <= 999);
    
    hundreds = a / 100;
    //@ assert hundreds == ((a) / 100);
    
    tens = (a / 10) % 10;
    //@ assert tens == (((a) / 10) % 10);
    
    units = a % 10;
    //@ assert units == ((a) % 10);
    
    result = (hundreds == 7) || (tens == 7) || (units == 7);
    //@ assert result == (((a) / 100) == 7 || (((a) / 10) % 10) == 7 || ((a) % 10) == 7);
    
    return result;
}
