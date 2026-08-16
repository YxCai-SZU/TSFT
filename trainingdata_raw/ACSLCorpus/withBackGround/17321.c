/*@
    predicate multiple_of_3_and_5(integer n) = n % 3 == 0 && n % 5 == 0;
    predicate multiple_of_7(integer n) = n % 7 == 0;
*/

/*@
    lemma multiple_of_3_and_5_15: multiple_of_3_and_5(15);
    lemma multiple_of_7_7: multiple_of_7(7);
*/

int main() {
    //@ assert multiple_of_3_and_5(15);
    //@ assert multiple_of_7(7);
    return 0;
}

/*@
    logic integer func_spec(integer N, integer M) = N * N - M;
    predicate func_pre(integer N, integer M) = 1 <= N <= 100 && 0 <= M <= N * N;
    predicate func_post(integer N, integer M, integer result) = result == func_spec(N, M);
*/

/*@
    requires func_pre(N, M);
    ensures func_post(N, M, \result);
*/
int func(int N, int M) {
    int result;
    //@ assert N * N <= 10000;
    //@ assert N * N >= M;
    result = N * N - M;
    return result;
}
