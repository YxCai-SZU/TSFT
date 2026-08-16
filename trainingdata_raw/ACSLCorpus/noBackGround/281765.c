#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100 &&
        1 <= (X) && (X) <= 200);
    ensures \result == (X <= A + B && A <= X);
    assigns \nothing;
*/
bool func(unsigned long long A, unsigned long long B, unsigned long long X)
{
    unsigned long long new_value;
    bool result;

    //@ assert (1 <= (A) && (A) <= 100 &&         1 <= (B) && (B) <= 100 &&         1 <= (X) && (X) <= 200);
    new_value = A + B;
    
    //@ assert new_value == A + B;
    
    if (X <= new_value && A <= X) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert ((result) == ((X) <= (((A)) + ((B))) && (A) <= (X)));
    return result;
}
