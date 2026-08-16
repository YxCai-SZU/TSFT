#include <limits.h>

/*@
    requires (1 <= (A) <= 10000);
    requires (1 <= (B) <= 10000);
    requires (1 <= (C) <= 10000);
    requires (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B));
    ensures \result >= ((C) * (D));
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int x;
    int y;
    int result;
    
    //@ assert (1 <= (A) <= 10000);
    //@ assert (1 <= (B) <= 10000);
    //@ assert ((A) * (B)) <= 10000 * 10000;
    x = A * B;
    
    //@ assert (1 <= (C) <= 10000);
    //@ assert (1 <= (D) <= 10000);
    //@ assert ((C) * (D)) <= 10000 * 10000;
    y = C * D;
    
    if (x > y) {
        result = x;
    } else {
        result = y;
    }
    
    //@ assert result == ((A) * (B)) || result == ((C) * (D));
    //@ assert result >= ((A) * (B));
    //@ assert result >= ((C) * (D));
    
    return result;
}
