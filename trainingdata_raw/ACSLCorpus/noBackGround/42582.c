#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 10) && (1 <= (B) && (B) <= 10) && (1 <= (C) && (C) <= 10);
    ensures \result == (A == 5 || B == 5 || C == 5);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool answer = false;
    
    //@ assert A == 5 || A != 5;
    if (A == 5) {
        answer = true;
    }
    
    //@ assert B == 5 || B != 5;
    if (B == 5) {
        answer = true;
    }
    
    //@ assert C == 5 || C != 5;
    if (C == 5) {
        answer = true;
    }
    
    //@ assert answer == (A == 5 || B == 5 || C == 5);
    return answer;
}
