#include <stdint.h>

/*@
    requires (-100 <= (a) && (a) <= 100);
    ensures \result == ((a) < 0 ? 0 : 100 + (a));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t result;
    //@ assert (-100 <= (a) && (a) <= 100);
    
    if (a < 0) {
        result = 0;
    } else {
        //@ assert 100 + a <= 200 && 100 + a >= 0;
        result = 100 + a;
    }
    
    //@ assert result == ((a) < 0 ? 0 : 100 + (a));
    return result;
}

int main(void)
{
    return 0;
}
