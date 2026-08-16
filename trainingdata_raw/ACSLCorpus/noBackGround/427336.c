#include <stdbool.h>
#include <stdint.h>

/*@ requires (1 <= (N) <= 1000000) && 
             ((N) == (N) && 
      \forall integer i; 0 <= i < (N) ==> 1 <= (numbers)[i] <= 1000) && 
             \valid(numbers + (0 .. N-1)); 
    ensures 0 <= \result <= N; */
uint32_t func(uint32_t N, uint32_t* numbers)
{
    uint32_t count = 0;
    uint32_t idx = 0;
    
    /*@ loop invariant 0 <= idx <= N;
        loop invariant 0 <= count <= idx;
        loop assigns idx, count;
        loop variant N - idx; */
    while (idx < N) {
        uint32_t a = numbers[idx];
        bool is_divisible = true;
        uint32_t i = 1;
        
        /*@ loop invariant 1 <= i <= 10;
            loop invariant \true;
            loop assigns i, is_divisible;
            loop variant 10 - i; */
        while (i < 10) {
            if (a % 10 == i) {
                is_divisible = false;
                break;
            }
            i++;
        }
        
        if (is_divisible) {
            count++;
        }
        idx++;
    }
    
    return count;
}
