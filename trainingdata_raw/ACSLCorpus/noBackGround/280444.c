#include <limits.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && 
             (-100 <= (C) <= 100) && (-100 <= (D) <= 100);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures \result >= ((A) * (B));
    ensures \result >= ((C) * (D));
    assigns \nothing;
*/
long func(long A, long B, long C, long D)
{
    long prod1;
    long prod2;
    long res;
    
    //@ assert -10000 <= A * B <= 10000;
    //@ assert -10000 <= C * D <= 10000;
    
    prod1 = A * B;
    prod2 = C * D;
    
    //@ assert prod1 == ((A) * (B));
    //@ assert prod2 == ((C) * (D));
    
    if (prod1 > prod2) {
        res = prod1;
    } else {
        res = prod2;
    }
    
    //@ assert res == prod1 || res == prod2;
    //@ assert res >= prod1 && res >= prod2;
    
    return res;
}
