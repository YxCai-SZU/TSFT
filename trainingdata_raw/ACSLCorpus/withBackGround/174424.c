#include <stdbool.h>

/*@
    predicate valid_inputs(integer A, integer B) =
        1 <= A && A <= 10000 &&
        1 <= B && B <= 10000;

    logic integer compute_C(integer A, integer B) = A * 10 + B;

    lemma no_overflow: \forall integer A; 1 <= A && A <= 10000 ==> A * 10 <= 100000;
*/

/*@
    requires valid_inputs(A, B);
    ensures \result == (compute_C(A, B) % 200 == 0);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B)
{
    // Variable declarations at scope top
    unsigned int C;
    bool is_divisible_by_200;
    unsigned int temp;

    //@ assert A * 10 <= 100000;
    
    C = A * 10 + B;
    
    temp = C;
    /*@
        loop invariant 1 <= A && A <= 10000;
        loop invariant 1 <= B && B <= 10000;
        loop invariant 0 <= temp && temp <= C;
        loop invariant temp % 200 == C % 200;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 200)
    {
        temp -= 200;
    }
    
    is_divisible_by_200 = (temp == 0);
    
    //@ assert is_divisible_by_200 == (compute_C(A, B) % 200 == 0);
    
    return is_divisible_by_200;
}

int main()
{
    return 0;
}
