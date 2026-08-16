#include <stdbool.h>

/*@
    requires (1 <= (N) && (N) <= 100);
    ensures \result == (((N) * 800) - ((((N)) / 15) * 200));
    assigns \nothing;
*/
int func(int N)
{
    int result;
    int count;
    int temp_N;
    
    result = N * 800;
    count = 0;
    temp_N = N;
    
    /*@
        loop invariant 1 <= N && N <= 100;
        loop invariant 0 <= temp_N && temp_N <= N;
        loop invariant count <= ((N) / 15);
        loop invariant temp_N == N - count * 15;
        loop invariant result == N * 800;
        loop assigns temp_N, count;
        loop variant temp_N;
    */
    while (temp_N >= 15)
    {
        temp_N -= 15;
        count += 1;
    }
    
    //@ assert 0 <= count * 200 && count * 200 <= 200 * ((N) / 15);
    
    result -= count * 200;
    
    //@ assert result == (((N) * 800) - ((((N)) / 15) * 200));
    
    return result;
}

int main(void)
{
    return 0;
}
