/*@
    requires 1 <= N <= 9;
    ensures \result == N * N * N;
    assigns \nothing;
*/
int func(int N)
{
    int cubes[9] = {
        1 * 1 * 1, 2 * 2 * 2, 3 * 3 * 3, 4 * 4 * 4, 5 * 5 * 5,
        6 * 6 * 6, 7 * 7 * 7, 8 * 8 * 8, 9 * 9 * 9
    };
    
    int result;
    
    //@ assert 1 <= N && N <= 9;
    //@ assert N - 1 >= 0 && N - 1 < 9;
    //@ assert N * N <= 81;
    //@ assert N * N * N <= 729;
    
    result = cubes[N - 1];
    
    //@ assert result == N * N * N;
    return result;
}
