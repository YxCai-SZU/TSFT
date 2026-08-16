#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000);
    ensures \result == ((N) / 3);
    assigns \nothing;
*/
int64_t func(int64_t N)
{
    int64_t result;
    int64_t temp_N;
    int64_t count;
    
    result = 0;
    temp_N = N;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_N <= N;
        loop invariant 0 <= count <= ((N) / 3);
        loop invariant N == temp_N + count * 3;
        loop invariant (1 <= (N) <= 1000);
        loop assigns temp_N, count;
        loop variant temp_N;
    */
    while (temp_N >= 3)
    {
        temp_N = temp_N - 3;
        count = count + 1;
    }
    
    result = count;
    
    //@ assert N == result * 3 + temp_N;
    //@ assert 0 <= result * 3 + temp_N <= 1000;
    //@ assert result * 3 + temp_N == N;
    
    return result;
}

int main()
{
    return 0;
}
