#include <limits.h>

/*@
    requires (-1000000000 <= (A) <= 1000000000) && (-1000000000 <= (B) <= 1000000000) && (-1000000000 <= (C) <= 1000000000) && (-1000000000 <= (D) <= 1000000000);
    ensures \result == A * D || \result == A * C || \result == B * D || \result == B * C;
    assigns \nothing;
*/
long long func(long long A, long long B, long long C, long long D) {
    long long max1;
    long long max2;
    long long ans;
    
    //@ assert (-1000000000 <= (A) <= 1000000000);
    //@ assert (-1000000000 <= (B) <= 1000000000);
    //@ assert (-1000000000 <= (C) <= 1000000000);
    //@ assert (-1000000000 <= (D) <= 1000000000);
    
    //@ assert (-1000000000000000000 <= (A) * (C) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (A) * (D) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (B) * (C) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (B) * (D) <= 1000000000000000000);
    
    if (A * C > A * D) {
        max1 = A * C;
    } else {
        max1 = A * D;
    }
    
    if (B * C > B * D) {
        max2 = B * C;
    } else {
        max2 = B * D;
    }
    
    if (max1 > max2) {
        ans = max1;
    } else {
        ans = max2;
    }
    
    //@ assert ans == A * D || ans == A * C || ans == B * D || ans == B * C;
    return ans;
}
