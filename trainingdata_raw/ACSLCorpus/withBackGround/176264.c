/*@
    predicate is_leq(integer a, integer b) = a <= b;

    lemma func_lemma:
        \forall integer a, b;
            a == 1 && b == 10 ==> is_leq(a, b);
*/

/*@
    requires a == 1;
    requires b == 10;
    ensures \result == 0;
*/
int func(int a, int b) {
    //@ assert a == 1;
    //@ assert b == 10;
    //@ assert a <= b;
    return 0;
}

int main() {
    int a = 1;
    int b = 10;
    //@ assert a <= b;
    return 0;
}
