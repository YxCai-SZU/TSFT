#include <stdbool.h>

/*@
    requires (1 <= (N) <= 1000);
    ensures \result == N / 3;
    assigns \nothing;
*/
int func(int N)
{
    int result = 0;
    int temp_N = N;
    int count = 0;

    /*@
        loop invariant ((((temp_N)) >= 0) && (temp_N) <= (N) &&
        (((count)) >= 0) && (count) <= (N) / 3 &&
        (N) == (temp_N) + 3 * (count));
        loop assigns temp_N, count;
        loop variant temp_N;
    */
    while (temp_N >= 3)
    {
        temp_N -= 3;
        count += 1;
    }

    //@ assert count == N / 3;
    result = count;
    
    return result;
}

int main()
{
    return 0;
}
