#include <stdint.h>

/*@
    requires (0 <= (x) <= 9);
    requires (0 <= (a) <= 9);
    ensures (x < a ==> \result == 0);
    ensures (x >= a ==> \result == 10);
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t a)
{
    int64_t ret;
    
    //@ assert (0 <= (x) <= 9);
    //@ assert (0 <= (a) <= 9);
    
    if (x < a) {
        ret = 0;
        //@ assert ret == 0;
    } else {
        ret = 10;
        //@ assert ret == 10;
    }
    
    //@ assert (x < a ==> ret == 0) && (x >= a ==> ret == 10);
    return ret;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
