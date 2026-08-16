#include <stdbool.h>

/*@
    requires 1 <= n <= 9;
    ensures \result == (n == 3 || n == 5 || n == 7);
    assigns \nothing;
*/
bool func(int n)
{
    //@ assert 1 <= n <= 9;
    bool result;
    
    switch (n) {
        case 3:
        case 5:
        case 7:
            //@ assert n == 3 || n == 5 || n == 7;
            result = true;
            break;
        default:
            //@ assert n != 3 && n != 5 && n != 7;
            result = false;
            break;
    }
    
    //@ assert result == (n == 3 || n == 5 || n == 7);
    return result;
}

/*@
    requires 1 <= n <= 9;
    ensures \result == (n == 3 || n == 5 || n == 7);
    assigns \nothing;
*/
bool func_bool(int n)
{
    //@ assert 1 <= n <= 9;
    bool result = false;
    
    if (n == 3 || n == 5 || n == 7) {
        result = true;
    }
    
    //@ assert result == (n == 3 || n == 5 || n == 7);
    return result;
}
