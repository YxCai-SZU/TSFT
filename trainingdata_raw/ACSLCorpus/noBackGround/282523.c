/*@
    requires (1 <= (N) && (N) <= 20) && (1 <= (M) && (M) <= 20);
    ensures (N > 9 || M > 9) ==> \result == -1;
    ensures (N <= 9 && M <= 9) ==> \result == N * M;
    assigns \nothing;
*/
int func(int N, int M)
{
    int max_val;
    int res;

    //@ assert (1 <= (N) && (N) <= 20) && (1 <= (M) && (M) <= 20);
    
    if (N > M) {
        max_val = N;
    } else {
        max_val = M;
    }

    //@ assert max_val == ((N) > (M) ? (N) : (M));
    
    if (max_val > 9) {
        //@ assert N > 9 || M > 9;
        res = -1;
    } else {
        //@ assert N <= 9 && M <= 9;
        //@ assert N * M <= 400;
        res = N * M;
    }
    
    return res;
}
