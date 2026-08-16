#include <stdbool.h>

/*@
    requires 1 <= a <= 13;
    requires 1 <= b <= 13;
    requires 1 <= c <= 13;
    ensures \result == (a + b + c >= 22);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert 1 <= a <= 13;
    //@ assert 1 <= b <= 13;
    //@ assert 1 <= c <= 13;
    //@ assert a + b <= 26;
    //@ assert a + b + c <= 39;
    
    unsigned int total;
    total = a + b + c;
    
    if (total >= 22)
    {
        //@ assert total >= 22;
        return true;
    }
    else
    {
        //@ assert total < 22;
        return false;
    }
}

/*@
    requires 1 <= a <= 13;
    requires 1 <= b <= 13;
    requires 1 <= c <= 13;
    ensures \result == (a + b + c >= 22);
    assigns \nothing;
*/
bool func_complex(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert 1 <= a <= 13;
    //@ assert 1 <= b <= 13;
    //@ assert 1 <= c <= 13;
    //@ assert a + b <= 26;
    //@ assert a + b + c <= 39;
    
    unsigned int total;
    total = a + b + c;
    
    //@ assert total == a + b + c;
    
    if (total >= 22)
    {
        //@ assert total >= 22;
        return true;
    }
    else
    {
        //@ assert total < 22;
        return false;
    }
}
