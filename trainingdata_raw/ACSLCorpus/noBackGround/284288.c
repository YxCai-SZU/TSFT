/*@
requires ((a) ==> (b));
requires (((a)) ==> (a));
ensures \result <==> (a && b);
assigns \nothing;
*/
int and_together(int a, int b) {
    //@ assert ((a) ==> (b));
    int ret = a && b;
    //@ assert ret <==> (a && b);
    return ret;
}

/*@
requires ((a) ==> (b));
requires (((a)) ==> (a));
ensures \result <==> (a || b);
assigns \nothing;
*/
int or_together(int a, int b) {
    //@ assert ((a) ==> (b));
    int ret = a || b;
    //@ assert ret <==> (a || b);
    return ret;
}

int main() {
    //@ assert ((1) ==> (1));
    //@ assert ((0) ==> (1));
    //@ assert !((1) ==> (0));
    return 0;
}
