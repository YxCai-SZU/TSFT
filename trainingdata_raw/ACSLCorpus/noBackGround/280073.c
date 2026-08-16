#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (N % 100) * 21 / 100 == N % 100;
    ensures \result == 0 ==> (N % 100) * 21 / 100 != N % 100;
*/
uint32_t func(uint32_t N)
{
    uint32_t num;
    uint32_t num2;

    //@ assert (1 <= (N) && (N) <= 100000);
    //@ assert 0 <= N % 100 && N % 100 <= 99;
    
    num = N % 100;
    num2 = (N % 100) * 21 / 100;

    //@ assert num == ((N) % 100);
    //@ assert num2 == (((N) % 100) * 21 / 100);

    if (num == num2)
    {
        //@ assert num == num2;
        //@ assert (N % 100) * 21 / 100 == N % 100;
        return 1;
    }
    else
    {
        //@ assert num != num2;
        //@ assert (N % 100) * 21 / 100 != N % 100;
        return 0;
    }
}
