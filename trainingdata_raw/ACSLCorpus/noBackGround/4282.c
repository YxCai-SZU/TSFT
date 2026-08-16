#include <limits.h>

/*@
    requires (-1000 <= (A) <= 1000) && (-1000 <= (B) <= 1000);
    ensures \result == ((A) + (B)) || \result == ((A) - (B)) || \result == ((A) * (B));
    ensures \result >= ((A) + (B)) && \result >= ((A) - (B)) && \result >= ((A) * (B));
*/
int func(int A, int B) {
    int add;
    int sub;
    int mul;
    int ans;
    
    //@ assert (-1000 <= (A) <= 1000);
    //@ assert (-1000 <= (B) <= 1000);
    
    add = A + B;
    sub = A - B;
    
    //@ assert -1000000 <= A * B <= 1000000;
    mul = A * B;
    
    ans = add;
    //@ assert ans >= ((A) + (B));
    
    if (ans > sub) {
        //@ assert ans >= ((A) - (B));
    } else {
        ans = sub;
        //@ assert ans >= ((A) - (B));
    }
    
    if (ans > mul) {
        //@ assert ans >= ((A) * (B));
    } else {
        ans = mul;
        //@ assert ans >= ((A) * (B));
    }
    
    //@ assert ans == ((A) + (B)) || ans == ((A) - (B)) || ans == ((A) * (B));
    return ans;
}
