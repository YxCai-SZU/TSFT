#include <limits.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100) && (-100 <= (D) <= 100);
    ensures \result == A*C || \result == A*D || \result == B*C || \result == B*D;
    ensures \result >= A*C && \result >= A*D && \result >= B*C && \result >= B*D;
*/
long func(long A, long B, long C, long D)
{
    long max_val;
    long temp_val;
    
    //@ assert (-100 <= (A) <= 100);
    //@ assert (-100 <= (C) <= 100);
    //@ assert (-10000 <= (A*C) <= 10000);
    
    max_val = A * C;
    
    //@ assert (-100 <= (A) <= 100);
    //@ assert (-100 <= (D) <= 100);
    //@ assert (-10000 <= (A*D) <= 10000);
    
    temp_val = A * D;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }
    
    //@ assert (-100 <= (B) <= 100);
    //@ assert (-100 <= (C) <= 100);
    //@ assert (-10000 <= (B*C) <= 10000);
    
    temp_val = B * C;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }
    
    //@ assert (-100 <= (B) <= 100);
    //@ assert (-100 <= (D) <= 100);
    //@ assert (-10000 <= (B*D) <= 10000);
    
    temp_val = B * D;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }
    
    return max_val;
}
