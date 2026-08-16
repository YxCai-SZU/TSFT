#include <stdbool.h>

/*@
    requires (1 <= (N) <= 10000);
    ensures \result == (N >= 2000 || (1000 * ((N / 100) + 1) >= N));
*/
bool func(int N)
{
    int temp_N;
    int count;
    int X;
    
    //@ assert (1 <= (N) <= 10000);
    temp_N = N;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_N <= N;
        loop invariant count <= N / 100;
        loop invariant temp_N == ((N) - 100 * (count));
        loop assigns temp_N, count;
        loop variant temp_N;
    */
    while (temp_N >= 100) {
        //@ assert temp_N >= 100;
        temp_N = temp_N - 100;
        count = count + 1;
        //@ assert temp_N == ((N) - 100 * (count));
    }
    
    //@ assert temp_N == ((N) - 100 * (count));
    X = count * 100;
    
    if (N >= 2000) {
        //@ assert N >= 2000;
        return true;
    } else if (X + 100 >= N) {
        //@ assert X + 100 >= N;
        return true;
    } else {
        //@ assert !(N >= 2000) && !(X + 100 >= N);
        return false;
    }
}
