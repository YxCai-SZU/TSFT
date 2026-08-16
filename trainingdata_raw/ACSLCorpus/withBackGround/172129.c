#include <stdint.h>

/*@
    predicate valid_n(uint32_t n) = n > 0 && n <= 0xFFFFFFFF / 2;
    
    logic integer diagonal(integer n) = n * 2 + 1;
    
    lemma no_overflow: \forall uint32_t n; valid_n(n) ==> n * 2 + 1 <= 0xFFFFFFFF;
*/

/*@
    requires valid_n(n);
    ensures \result == diagonal(n);
    assigns \nothing;
*/
uint32_t find_diagonal(uint32_t n)
{
    //@ assert n > 0;
    //@ assert n <= 0xFFFFFFFF / 2;
    //@ assert n * 2 + 1 <= 0xFFFFFFFF;
    
    return n * 2 + 1;
}

int main()
{
    return 0;
}
