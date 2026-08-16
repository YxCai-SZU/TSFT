#include <stdbool.h>

/*@
    requires -40 <= x <= 40;
    ensures \result == true ==> ((x) >= 30);
    ensures \result == false ==> ((x) < 30);
    assigns \nothing;
*/
bool func(int x)
{
    bool result;
    //@ assert -40 <= x <= 40;
    
    if (x >= 30) {
        //@ assert ((x) >= 30);
        result = true;
    } else {
        //@ assert ((x) < 30);
        result = false;
    }
    
    return result;
}

/*@
    requires -40 <= a <= 40;
    requires -40 <= b <= 40;
    requires -40 <= c <= 40;
    ensures \result == true ==> (((a) >= 30) && ((b) >= 30) && ((c) >= 30));
    ensures \result == false ==> (((a) < 30) || ((b) < 30) || ((c) < 30));
    assigns \nothing;
*/
bool func2(int a, int b, int c)
{
    bool result;
    //@ assert -40 <= a <= 40;
    //@ assert -40 <= b <= 40;
    //@ assert -40 <= c <= 40;
    
    if (a < 30 || b < 30 || c < 30) {
        //@ assert ((a) < 30) || ((b) < 30) || ((c) < 30);
        result = false;
    } else {
        //@ assert ((a) >= 30) && ((b) >= 30) && ((c) >= 30);
        result = true;
    }
    
    return result;
}
