#include <limits.h>

/*@
    requires (1 <= (N) <= 1000);
    ensures \result == N / 3;
    assigns \nothing;
*/
int func(int N)
{
    int result;
    int count;
    int abs_N;
    
    result = 0;
    count = 0;
    
    if (N < 0) {
        abs_N = -N;
    } else {
        abs_N = N;
    }
    
    /*@
        loop invariant 0 <= abs_N <= 1000;
        loop invariant 0 <= count <= N / 3;
        loop invariant abs_N == N - 3 * count;
        loop invariant (1 <= (N) <= 1000);
        loop assigns abs_N, count;
        loop variant abs_N;
    */
    while (abs_N >= 3) {
        abs_N -= 3;
        count += 1;
    }
    
    //@ assert abs_N == N - 3 * count;
    //@ assert abs_N < 3;
    //@ assert N - 3 * count < 3;
    //@ assert N < 3 * (count + 1);
    //@ assert N / 3 == count;
    
    if (N < 0) {
        result = -count;
    } else {
        result = count;
    }
    
    return result;
}

int main()
{
    return 0;
}
