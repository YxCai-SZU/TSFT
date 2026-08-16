#include <stdint.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    ensures \result == A * B;
    ensures \result >= 1;
    ensures \result <= 10000;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B)
{
    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert A * B >= 1;
    //@ assert A * B <= 10000;
    
    return A * B;
}

int main()
{
    return 0;
}
