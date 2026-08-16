#include <limits.h>

/*@
    predicate valid_params(integer N, integer A, integer B) =
        1 <= N <= 20 && 1 <= A <= 50 && 1 <= B <= 50;
    
    logic integer product(integer N, integer A) = N * A;
    
    lemma product_bounds:
        \forall integer N, A;
        valid_params(N, A, 1) ==> product(N, A) <= 1000;
*/

/*@
    requires valid_params(N, A, B);
    ensures \result == product(N, A) || \result == B;
    ensures \result <= product(N, A);
    ensures \result <= B;
    assigns \nothing;
*/
int func(int N, int A, int B)
{
    // Variable declarations at scope top
    int product;
    int result;
    
    // Precondition verification
    //@ assert 1 <= N && N <= 20;
    //@ assert 1 <= A && A <= 50;
    //@ assert 1 <= B && B <= 50;
    
    // Product calculation with overflow prevention
    //@ assert product(N, A) <= 1000;
    product = N * A;
    
    if (product < B)
    {
        result = product;
        //@ assert result == product(N, A);
    }
    else
    {
        result = B;
        //@ assert result == B;
    }
    
    // Postcondition verification
    //@ assert result <= product(N, A);
    //@ assert result <= B;
    
    return result;
}
