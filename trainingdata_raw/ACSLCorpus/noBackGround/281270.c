#include <stdint.h>

/*@
    requires a >= -100 && a <= 100;
    requires b >= -100 && b <= 100;
    ensures \result == a || \result == b;
    ensures (((a) >= (b) && (\result) == (a)) || ((b) > (a) && (\result) == (b)));
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t max_value;
    int64_t min_value;
    
    //@ assert a >= -100 && a <= 100;
    //@ assert b >= -100 && b <= 100;
    
    if (a > b) {
        max_value = a;
        min_value = b;
    } else {
        max_value = b;
        min_value = a;
    }
    
    //@ assert (a >= b && max_value == a) || (b > a && max_value == b);
    
    return max_value;
}

/*@
    ensures \result == 0;
*/
int64_t input_number(void)
{
    return 0;
}

/*@
    ensures \result == 0;
*/
int64_t input(void)
{
    return 0;
}

int main(void)
{
    return 0;
}
