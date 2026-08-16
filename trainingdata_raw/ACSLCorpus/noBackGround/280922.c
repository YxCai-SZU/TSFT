#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures ((\result) >= 0);
    ensures ((\result) <= 100);
    ensures ((\result) == 100 ==> (n) >= 13);
    ensures ((\result) == 0 ==> (n) <= 12);
*/
int32_t func(uint32_t n)
{
    int32_t result;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    if (n >= 13)
    {
        //@ assert n >= 13;
        result = 100;
    }
    else
    {
        //@ assert n <= 12;
        result = 0;
    }
    
    //@ assert ((result) >= 0);
    //@ assert ((result) <= 100);
    //@ assert ((result) == 100 ==> (n) >= 13);
    //@ assert ((result) == 0 ==> (n) <= 12);
    
    return result;
}

int main()
{
    return 0;
}
