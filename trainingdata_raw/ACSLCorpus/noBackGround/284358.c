#include <stdbool.h>

/*@
    requires 10 <= a <= 99;
    ensures \result == true <==> (((a) / 10) % 10 == 9 || (a) % 10 == 9);
    assigns \nothing;
*/
bool func(int a)
{
    bool result;
    //@ ghost int original_a = a;

    //@ assert 10 <= original_a <= 99;

    if ((a / 10) % 10 == 9 || a % 10 == 9) {
        //@ assert (((original_a) / 10) % 10 == 9 || (original_a) % 10 == 9);
        result = true;
    } else {
        //@ assert !(((original_a) / 10) % 10 == 9 || (original_a) % 10 == 9);
        result = false;
    }

    //@ assert result == true <==> (((original_a) / 10) % 10 == 9 || (original_a) % 10 == 9);
    return result;
}
