/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == 1 <==> ((a) <= (b) && (b) <= (c));
*/
int func(int a, int b, int c) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
        loop assigns i;
    */
    while (i < 3) {
        //@ assert (1 <= (a) <= 100);
        //@ assert (1 <= (b) <= 100);
        //@ assert (1 <= (c) <= 100);
        i++;
    }
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    return (a <= b && b <= c) ? 1 : 0;
}

int main() {
    return 0;
}
