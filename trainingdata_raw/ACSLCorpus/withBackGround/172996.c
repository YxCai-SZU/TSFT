#include <stdint.h>

/*@
    predicate valid_index(integer idx) = 0 <= idx < 32;
    
    logic integer array_value(integer idx) =
        idx == 0 ? 1 :
        idx == 1 ? 1 :
        idx == 2 ? 1 :
        idx == 3 ? 2 :
        idx == 4 ? 1 :
        idx == 5 ? 2 :
        idx == 6 ? 1 :
        idx == 7 ? 5 :
        idx == 8 ? 2 :
        idx == 9 ? 2 :
        idx == 10 ? 1 :
        idx == 11 ? 5 :
        idx == 12 ? 1 :
        idx == 13 ? 2 :
        idx == 14 ? 1 :
        idx == 15 ? 14 :
        idx == 16 ? 1 :
        idx == 17 ? 5 :
        idx == 18 ? 1 :
        idx == 19 ? 5 :
        idx == 20 ? 2 :
        idx == 21 ? 2 :
        idx == 22 ? 1 :
        idx == 23 ? 15 :
        idx == 24 ? 2 :
        idx == 25 ? 2 :
        idx == 26 ? 5 :
        idx == 27 ? 4 :
        idx == 28 ? 1 :
        idx == 29 ? 4 :
        idx == 30 ? 1 :
        51;
    
    lemma index_in_range: \forall integer n; 1 <= n <= 32 ==> 0 <= n-1 < 32;
    lemma result_valid: \forall integer idx; valid_index(idx) ==> 
        array_value(idx) == 1 || array_value(idx) == 2 || 
        array_value(idx) == 5 || array_value(idx) == 14 || 
        array_value(idx) == 15 || array_value(idx) == 51 || 
        array_value(idx) == 4;
*/

/*@
    requires 1 <= N <= 32;
    ensures \result == 1 || \result == 2 || \result == 5 || 
            \result == 14 || \result == 15 || \result == 51 || \result == 4;
*/
int32_t func(uint32_t N)
{
    int32_t v[32];
    uint32_t index;
    int32_t result;
    
    v[0] = 1;
    v[1] = 1;
    v[2] = 1;
    v[3] = 2;
    v[4] = 1;
    v[5] = 2;
    v[6] = 1;
    v[7] = 5;
    v[8] = 2;
    v[9] = 2;
    v[10] = 1;
    v[11] = 5;
    v[12] = 1;
    v[13] = 2;
    v[14] = 1;
    v[15] = 14;
    v[16] = 1;
    v[17] = 5;
    v[18] = 1;
    v[19] = 5;
    v[20] = 2;
    v[21] = 2;
    v[22] = 1;
    v[23] = 15;
    v[24] = 2;
    v[25] = 2;
    v[26] = 5;
    v[27] = 4;
    v[28] = 1;
    v[29] = 4;
    v[30] = 1;
    v[31] = 51;
    
    index = N - 1;
    
    //@ assert 0 <= index < 32;
    
    result = v[index];
    
    //@ assert result == 1 || result == 2 || result == 5 || result == 14 || result == 15 || result == 51 || result == 4;
    
    return result;
}
