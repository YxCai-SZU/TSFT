/*@
    predicate is_even(integer x) = x % 2 == 0;

    lemma func0: \forall integer m, n; is_even(m) ==> is_even(m + 2);
    lemma func1: \forall integer m, n; is_even(m) ==> is_even(m + 4);
    lemma func2: \forall integer m, n; is_even(m) ==> is_even(m + 6);
    lemma func3: \forall integer m, n; is_even(m) ==> is_even(m + 8);
    lemma func4: \forall integer m, n; is_even(m) ==> is_even(m + 10);
    lemma func5: \forall integer m, n; is_even(m) ==> is_even(m + 12);
    lemma calc_example_10: \forall integer m, n; is_even(m) ==> is_even(m + 4);
    lemma calc_example_11: \forall integer m, n; is_even(m) ==> is_even(m + 6);
*/

/*@
    requires is_even(m);
    ensures is_even(m + 2);
*/
void func0(int m, int n) {
    //@ assert is_even(m);
    //@ assert is_even(m + 2);
}

/*@
    requires is_even(m);
    ensures is_even(m + 4);
*/
void func1(int m, int n) {
    //@ assert is_even(m);
    //@ assert is_even(m + 4);
}

/*@
    requires is_even(m);
    ensures is_even(m + 6);
*/
void func2(int m, int n) {
    //@ assert is_even(m);
    //@ assert is_even(m + 6);
}

/*@
    requires is_even(m);
    ensures is_even(m + 8);
*/
void func3(int m, int n) {
    //@ assert is_even(m);
    //@ assert is_even(m + 8);
}

/*@
    requires is_even(m);
    ensures is_even(m + 10);
*/
void func4(int m, int n) {
    //@ assert is_even(m);
    //@ assert is_even(m + 10);
}

/*@
    requires is_even(m);
    ensures is_even(m + 12);
*/
void func5(int m, int n) {
    //@ assert is_even(m);
    //@ assert is_even(m + 12);
}

/*@
    requires is_even(m);
    ensures is_even(m + 4);
*/
void calc_example_10(int m, int n) {
    //@ assert is_even(m);
    //@ assert is_even(m + 4);
}

/*@
    requires is_even(m);
    ensures is_even(m + 6);
*/
void calc_example_11(int m, int n) {
    //@ assert is_even(m);
    //@ assert is_even(m + 6);
}

int main() {
    return 0;
}
