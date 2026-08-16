#include <stdbool.h>

/*@
    requires (1 <= (X) && (X) < (Y) && (Y) <= 12);
    ensures \result == true;
    assigns \nothing;
*/
bool func(long X, long Y)
{
    long X_unsigned;
    long Y_unsigned;
    long difference;
    long remainder;
    long result;
    long abs_result;
    bool ret_val;

    //@ assert (1 <= (X) && (X) < (Y) && (Y) <= 12);
    
    if (X < 0) {
        X_unsigned = -X;
    } else {
        X_unsigned = X;
    }
    
    if (Y < 0) {
        Y_unsigned = -Y;
    } else {
        Y_unsigned = Y;
    }

    if (X > Y) {
        difference = X - Y;
    } else {
        difference = Y - X;
    }
    
    remainder = X_unsigned % 12;
    
    if (X < 0) {
        result = -remainder;
    } else {
        result = remainder;
    }

    if (result < 0) {
        abs_result = -result;
    } else {
        abs_result = result;
    }

    if ((difference == 1) || (difference == 2) || (difference == 3) || 
        (difference == 4) || (difference == 5) || (difference == 6) || 
        (difference == 7) || (difference == 8) || (difference == 9) || 
        (difference == 10) || (difference == 11)) {
        //@ assert (1 <= (difference) && (difference) <= 11);
        ret_val = true;
    } else {
        //@ assert !(1 <= (difference) && (difference) <= 11);
        ret_val = false;
    }
    
    //@ assert ret_val == true;
    return ret_val;
}
