#include <stdbool.h>

/*@
    requires (\valid((p)) && \valid((p)+1) && \valid((p)+2) &&
        (p)[0] >= 1 && (p)[0] <= 100 &&
        (p)[1] >= 1 && (p)[1] <= 20 &&
        (p)[2] >= 1 && (p)[2] <= 2000);
    ensures \result >= 0;
    ensures \result == p[0] * p[1] || \result == p[2];
    ensures \result <= p[0] * p[1] + p[2];
    assigns \nothing;
*/
int func(int *p)
{
    int x;
    
    //@ assert p[0] >= 1 && p[0] <= 100;
    //@ assert p[1] >= 1 && p[1] <= 20;
    //@ assert p[2] >= 1 && p[2] <= 2000;
    //@ assert p[0] * p[1] <= 2000;
    
    x = p[0] * p[1];
    
    if (x < p[2]) {
        return x;
    } else {
        return p[2];
    }
}
