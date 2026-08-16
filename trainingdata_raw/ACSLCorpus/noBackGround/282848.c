/*@
    requires (1 <= (N) <= 100 && 0 <= (M) <= (N));
    ensures \result == (N == M);
    assigns \nothing;
*/
int func(int N, int M) {
    int result;
    //@ assert N == M ==> N == M;
    result = (N == M);
    return result;
}

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) - ((b) * 2)) || \result == 0;
    assigns \nothing;
*/
int func2(int a, int b) {
    int c;
    int result;
    c = a - (b * 2);
    if (c > 0) {
        result = c;
    } else {
        //@ assert c <= 0;
        result = 0;
    }
    return result;
}
