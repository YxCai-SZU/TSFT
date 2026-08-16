#include <stdint.h>
#include <stdbool.h>

/*@
    requires length == 2 && ((1 <= ((numbers[0])) && ((numbers[0])) <= 12) && (1 <= ((numbers[1])) && ((numbers[1])) <= 31));
    ensures \result >= 0 || \result == -1;
*/
int32_t func(uint32_t* numbers, uint32_t length)
{
    uint32_t v[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    uint32_t month;
    uint32_t day;
    
    //@ assert length == 2;
    //@ assert (1 <= (numbers[0]) && (numbers[0]) <= 12);
    //@ assert (1 <= (numbers[1]) && (numbers[1]) <= 31);
    
    month = numbers[0] - 1;
    day = numbers[1];
    
    //@ assert month < 12;
    //@ assert day <= 31;
    
    if (v[month] < day) {
        //@ assert v[month] < day;
        return -1;
    } else {
        //@ assert v[month] >= day;
        return 0;
    }
}
