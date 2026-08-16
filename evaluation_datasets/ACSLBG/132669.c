#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    logic integer division_by_2(integer sum) =
        sum / 2;
*/


int32_t func(uint64_t a, uint64_t b)
{
    uint64_t sum;
    uint64_t cnt;
    uint64_t temp;
    
    //@ assert valid_inputs(a, b);
    sum = a + b;
    cnt = 0;
    temp = sum;
    
    
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        cnt += 1;
        //@ assert temp + 2 * cnt == sum;
    }
    
    if (temp == 1)
    {
        cnt += 1;
    }
    
    //@ assert cnt >= 0;
    return (cnt > 0) ? 1 : 0;
}
