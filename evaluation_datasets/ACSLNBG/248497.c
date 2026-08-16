#include <stdint.h>


int64_t func(int64_t r)
{
    int64_t pi = 314159;
    int64_t two = 2;
    int64_t scale = 100000;
    int64_t result = 0;
    int64_t temp = two * pi * r;
    
    //@ assert temp == 2 * 314159 * r;
    
    
    while (temp >= scale)
    {
        result += 1;
        temp -= scale;
    }
    
    //@ assert result * scale + temp == two * pi * r;
    
    return result;
}

int main(void)
{
    return 0;
}
