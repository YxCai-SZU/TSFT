#include <stdbool.h>

/*@
    requires ((A) >= 1 && (A) <= 10000 &&
        (B) >= 1 && (B) <= 10000 &&
        (C) >= 1 && (C) <= 10000);
    ensures \result >= 0;
    ensures \result <= C;
    assigns \nothing;
*/
int func(int A, int B, int C)
{
    int ans;
    
    // First conditional assignment
    //@ assert ((A) >= 1 && (A) <= 10000 &&         (B) >= 1 && (B) <= 10000 &&         (C) >= 1 && (C) <= 10000);
    if (A <= C) {
        ans = A + B;
        //@ assert ans == A + B;
    } else {
        ans = B + C;
        //@ assert ans == B + C;
    }
    
    // Second conditional assignment
    //@ assert ans == (((A) <= (C)) ? ((A) + (B)) : ((B) + (C)));
    if (ans <= C) {
        //@ assert ans <= C;
    } else {
        ans = C;
        //@ assert ans == C;
    }
    
    // Final verification
    //@ assert ans == ((((((A)) <= ((C))) ? (((A)) + ((B))) : (((B)) + ((C)))) <= (C)) ? ((((A)) <= ((C))) ? (((A)) + ((B))) : (((B)) + ((C)))) : (C));
    //@ assert ans >= 0 && ans <= C;
    
    return ans;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    // Test cases from original Rust code
    assert(func(1, 2, 3) == 3);
    assert(func(10, 20, 30) == 30);
    assert(func(100, 200, 300) == 300);
    assert(func(1000, 2000, 3000) == 3000);
    
    return 0;
}
#endif
