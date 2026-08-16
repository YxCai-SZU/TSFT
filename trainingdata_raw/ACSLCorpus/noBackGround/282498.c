#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((((a) - 1) / 3 + 1) <= (((b) - 1) / 3));
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    unsigned long long a_modified;
    unsigned long long b_modified;
    unsigned long long a_result;
    unsigned long long b_result;
    bool result;
    
    a_modified = a;
    b_modified = b;
    
    a_modified -= 1;
    b_modified -= 1;
    
    a_result = a_modified / 3 + 1;
    b_result = b_modified / 3;
    
    //@ assert a_result == (a - 1) / 3 + 1;
    //@ assert b_result == (b - 1) / 3;
    
    result = a_result <= b_result;
    
    return result;
}
