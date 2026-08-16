#include <stdint.h>

/*@
    predicate is_zero(integer x) = x == 0;
    predicate is_one(integer x) = x == 1;
    
    logic integer complement(integer x) = 1 - x;
    
    lemma complement_zero: \forall integer x; is_zero(x) ==> complement(x) == 1;
    lemma complement_one: \forall integer x; is_one(x) ==> complement(x) == 0;
*/

/*@
    requires 0 <= X <= 1;
    ensures (X == 0 ==> \result == 1);
    ensures (X == 1 ==> \result == 0);
*/
int32_t func(uint32_t X)
{
    int32_t result;
    
    //@ assert X == 0 || X == 1;
    
    //@ assert X == 0 ==> 1 - (int32_t)X == 1;
    //@ assert X == 1 ==> 1 - (int32_t)X == 0;
    
    result = 1 - (int32_t)X;
    
    //@ assert (X == 0 ==> result == 1) && (X == 1 ==> result == 0);
    
    return result;
}

int main()
{
    return 0;
}
