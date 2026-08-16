#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == (((a) * 2 + 1) <= ((b) * 3));
*/
bool func(int a, int b)
{
    int a_new;
    int b_new;
    bool result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    a_new = a * 2 + 1;
    b_new = b * 3;
    
    //@ assert a_new == a * 2 + 1;
    //@ assert b_new == b * 3;
    
    //@ assert 1 <= a_new <= 201;
    //@ assert 1 <= b_new <= 300;
    
    result = a_new <= b_new;
    
    //@ assert result == (a_new <= b_new);
    return result;
}
