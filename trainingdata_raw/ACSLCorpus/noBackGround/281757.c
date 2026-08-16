#include <stdbool.h>
#include <stdint.h>

/*@
    requires 1 <= x <= 1000000000;
    ensures ((x) % 2 == 0) ==> \result == x;
    ensures !((x) % 2 == 0) ==> \result == 2 * x;
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t ans;
    //@ assert x >= 1 && x <= 1000000000;
    
    if (x % 2 == 0) {
        ans = x;
    } else {
        ans = 2 * x;
    }
    
    return ans;
}

/*@
    requires \true;
    ensures \result == (a_first < b_first);
    assigns \nothing;
*/
bool ord(uint32_t a_first, uint32_t a_second, uint32_t b_first, uint32_t b_second)
{
    bool result;
    
    if (a_first < b_first) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}

/*@
    requires \true;
    ensures \result[0] == 1;
    ensures \result[1] == 10;
    ensures \result[2] == 3;
    assigns \result[0..2];
*/
uint32_t* vector_example(void)
{
    static uint32_t vec[3];
    
    vec[0] = 1;
    //@ assert vec[0] == 1;
    
    vec[1] = 2;
    //@ assert vec[1] == 2;
    
    vec[2] = 3;
    //@ assert vec[2] == 3;
    
    vec[1] = 10;
    //@ assert vec[1] == 10;
    
    return vec;
}
