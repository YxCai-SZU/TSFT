#include <stdbool.h>

/*@
    requires -180 <= x <= 180;
    ensures \result == (x == 90 || x == -90 || x == 0);
    assigns \nothing;
 */
bool func(int x)
{
    int abs_x;
    bool is_multiple = false;
    int temp;

    //@ assert -180 <= x && x <= 180;
    
    if (x < 0) {
        abs_x = x * -1;
    } else {
        abs_x = x;
    }
    
    //@ assert 0 <= abs_x <= 180;
    
    temp = abs_x;
    
    /*@
        loop invariant 0 <= temp <= abs_x;
        loop invariant temp % 90 == abs_x % 90;
        loop assigns temp;
        loop variant temp;
     */
    while (temp >= 90) {
        //@ assert temp >= 90;
        temp -= 90;
        //@ assert temp >= 0;
    }
    
    if (temp == 0) {
        is_multiple = true;
    }
    
    //@ assert is_multiple == (abs_x % 90 == 0);
    return is_multiple && (x == 90 || x == -90 || x == 0);
}
