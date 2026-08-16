#include <stdint.h>


uint32_t find_triangular_num(uint32_t n)
{
    //@ assert (0 <= (n) && (n) <= 65535);
    //@ assert n * (n + 1) <= 4294967295;
    //@ assert (n * (n + 1)) / 2 <= 2147483647;
    
    return (n * (n + 1)) / 2;
}
