/*@
    requires (0 <= (X) && (X) <= 9) && (0 <= (A) && (A) <= 9);
    ensures \result == ((X) < (A) ? 0 : 10);
    ensures (X < A ==> \result == 0) && (X >= A ==> \result == 10);
*/
int func(int X, int A)
{
    int result;
    //@ assert (0 <= (X) && (X) <= 9) && (0 <= (A) && (A) <= 9);
    if (X < A) {
        result = 0;
        //@ assert X < A && result == 0;
    } else {
        result = 10;
        //@ assert X >= A && result == 10;
    }
    //@ assert result == ((X) < (A) ? 0 : 10);
    return result;
}

/*@
    requires ((len) >= 0 && \valid((s) + (0 .. (len)-1))) && len > 0;
    ensures \result == len - 1;
*/
unsigned int example9(unsigned char *s, unsigned int len)
{
    unsigned int result;
    //@ assert ((len) >= 0 && \valid((s) + (0 .. (len)-1))) && len > 0;
    result = len - 1;
    //@ assert result == len - 1;
    //@ assert ((result)) == result;
    return result;
}
