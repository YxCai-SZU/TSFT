#include <stdint.h>

/*@
    requires (0 <= (X) <= 9) && (0 <= (A) <= 9);
    ensures (((X) < (A) ==> (\result) == 0) && ((X) >= (A) ==> (\result) == 10));
    assigns \nothing;
*/
int32_t func(uint32_t X, uint32_t A)
{
    int32_t res;
    
    //@ assert (0 <= (X) <= 9) && (0 <= (A) <= 9);
    
    if (X < A) {
        res = 0;
        //@ assert X < A ==> res == 0;
    } else {
        //@ assert X >= A;
        //@ assert 10 <= 10 && 10 >= 10;
        res = 10;
        //@ assert X >= A ==> res == 10;
    }
    
    //@ assert (((X) < (A) ==> (res) == 0) && ((X) >= (A) ==> (res) == 10));
    return res;
}
