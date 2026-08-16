#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    int32_t a1;
    int32_t a2;
    int32_t a3;
    int32_t ans;
    
    //@ assert (1 <= (a) <= 10);
    
    a1 = a;
    
    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= ((a) * (a)) && ((a) * (a)) <= 100;
    a2 = a * a;
    
    //@ assert 1 <= ((a) * (a) * (a)) && ((a) * (a) * (a)) <= 1000;
    a3 = a * a * a;
    
    ans = a1 + a2 + a3;
    
    //@ assert a2 == ((a) * (a));
    //@ assert a3 == ((a) * (a) * (a));
    //@ assert ans >= 1;
    //@ assert ans == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    
    return ans;
}

int main(void)
{
    return 0;
}
