#include <stdbool.h>

/*@
    requires (1 <= (m) && (m) <= 50000);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result * 108 >= m * 100;
    ensures \result >= 0 ==> (\result * 108) - (m * 100) <= 999;
*/
int func(int m)
{
    int i;
    int result;
    int test_value;
    int remainder;
    
    i = 0;
    /*@
        loop invariant (0 <= (i) && (i) <= 50000);
        loop invariant (1 <= (m) && (m) <= 50000);
        loop assigns i, result, test_value, remainder;
        loop variant 50000 - i;
    */
    while (i < 50000)
    {
        test_value = i * 108;
        remainder = test_value;
        
        /*@
            loop invariant (0 <= (remainder) && (remainder) <= (test_value));
            loop invariant test_value == ((i) * 108);
            loop invariant (1 <= (m) && (m) <= 50000);
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= 100)
        {
            remainder -= 100;
        }
        
        if (remainder == 0)
        {
            //@ assert remainder == 0;
            if (i * 108 >= m * 100 && (i * 108 - m * 100) <= 999)
            {
                result = i;
                //@ assert ((result) >= 0 ==> ((result) * 108 >= (m) * 100) && (((result) * 108) - ((m) * 100) <= 999));
                return result;
            }
        }
        
        i += 1;
    }
    
    result = -1;
    //@ assert result == -1;
    return result;
}
