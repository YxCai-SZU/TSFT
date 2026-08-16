/*@
requires 0 <= x <= 1;
ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
assigns \nothing;
*/
int func(int x) {
    int result;
    //@ assert 0 <= x <= 1;
    result = (x == 0) ? 1 : 0;
    //@ assert (x == 0 ==> result == 1) && (x == 1 ==> result == 0);
    return result;
}

/*@
requires 0 <= x <= 1;
ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
assigns \nothing;
*/
int func_spec(int x) {
    int result;
    //@ assert 0 <= x <= 1;
    if (x == 0) {
        //@ assert ((x) == 0);
        //@ assert x == 0;
        result = 1;
    } else {
        //@ assert ((x) == 1);
        //@ assert x == 1;
        result = 0;
    }
    //@ assert (x == 0 ==> result == 1) && (x == 1 ==> result == 0);
    return result;
}
