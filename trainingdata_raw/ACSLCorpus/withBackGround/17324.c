#include <stdint.h>

/*@ predicate A_in_range(integer a) = 1 <= a && a <= 100; */
/*@ predicate B_in_range(integer b) = 1 <= b && b <= 100; */
/*@ logic integer multiply(integer a, integer b) = a * b; */

/*@
    requires A_in_range(A) && B_in_range(B);
    ensures \result == multiply(A, B);
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert A <= 100 && B <= 100;
    //@ assert multiply(A, B) <= 10000;
    
    result = A * B;
    return result;
}

int main()
{
    return 0;
}
