/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == (a * b > c * d);
*/
int func(int a, int b, int c, int d) {
    // Variable declarations at the top
    int result;

    //@ assert (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    //@ assert (a * b > c * d ==> a * b > c * d);
    //@ assert (!(a * b > c * d) ==> !(a * b > c * d));

    result = (a * b > c * d);
    return result;
}
