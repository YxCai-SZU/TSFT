#include <stddef.h>
#include <stdint.h>

/*@ requires (1 <= (input) && (input) <= 32);
    ensures \result > 0;
    ensures \result <= 100;
    assigns \nothing;
 */
int32_t func(int32_t input)
{
    int32_t arr[32];
    size_t len;
    size_t index;
    int32_t result;
    
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 1;
    arr[5] = 2;
    arr[6] = 1;
    arr[7] = 5;
    arr[8] = 2;
    arr[9] = 2;
    arr[10] = 1;
    arr[11] = 5;
    arr[12] = 1;
    arr[13] = 2;
    arr[14] = 1;
    arr[15] = 14;
    arr[16] = 1;
    arr[17] = 5;
    arr[18] = 1;
    arr[19] = 5;
    arr[20] = 2;
    arr[21] = 2;
    arr[22] = 1;
    arr[23] = 15;
    arr[24] = 2;
    arr[25] = 2;
    arr[26] = 5;
    arr[27] = 4;
    arr[28] = 1;
    arr[29] = 4;
    arr[30] = 1;
    arr[31] = 51;
    
    len = 32;
    index = (size_t)(input - 1);
    
    //@ assert (1 <= (input) && (input) <= 32);
    
    if (index < len)
    {
        //@ assert index < 32;
        result = arr[index];
        //@ assert result == ((input) == 1 ? 1 :     (input) == 2 ? 1 :     (input) == 3 ? 1 :     (input) == 4 ? 2 :     (input) == 5 ? 1 :     (input) == 6 ? 2 :     (input) == 7 ? 1 :     (input) == 8 ? 5 :     (input) == 9 ? 2 :     (input) == 10 ? 2 :     (input) == 11 ? 1 :     (input) == 12 ? 5 :     (input) == 13 ? 1 :     (input) == 14 ? 2 :     (input) == 15 ? 1 :     (input) == 16 ? 14 :     (input) == 17 ? 1 :     (input) == 18 ? 5 :     (input) == 19 ? 1 :     (input) == 20 ? 5 :     (input) == 21 ? 2 :     (input) == 22 ? 2 :     (input) == 23 ? 1 :     (input) == 24 ? 15 :     (input) == 25 ? 2 :     (input) == 26 ? 2 :     (input) == 27 ? 5 :     (input) == 28 ? 4 :     (input) == 29 ? 1 :     (input) == 30 ? 4 :     (input) == 31 ? 1 :     51);
        //@ assert result > 0;
        return result;
    }
    else
    {
        result = 100;
        //@ assert result > 0;
        return result;
    }
}
