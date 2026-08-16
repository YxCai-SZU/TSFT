/*@
predicate prop(integer v) = v <= 200;

lemma example_lemma:
    \forall integer u; 100 <= u <= 200 ==> u <= 200;
*/

/*@
requires 100 <= u <= 200;
ensures \result <= 200;
assigns \nothing;
*/
int example(int u) {
    //@ assert 100 <= 200;
    //@ assert 200 <= 200;
    //@ assert 150 <= 200;
    return u;
}

int main() {
    return 0;
}
