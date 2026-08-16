#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) * (1 + ((a)) * (1 + ((a)))));
    ensures 1 <= \result <= 1110;
*/
int32_t func(int32_t a)
{
    int32_t a_1;
    
    //@ assert (1 <= (a) <= 10);
    //@ assert 1 <= a && a <= 10;
    
    //@ assert 1 + a * (1 + a) >= 1;
    //@ assert 1 + a * (1 + a) <= 111;
    
    a_1 = 1 + a * (1 + a);
    
    //@ assert a_1 == (1 + (a) * (1 + (a)));
    //@ assert 1 <= a_1 && a_1 <= 111;
    
    //@ assert a * a_1 >= 1;
    //@ assert a * a_1 <= 1110;
    
    return a * a_1;
}

int main()
{
    return 0;
}
