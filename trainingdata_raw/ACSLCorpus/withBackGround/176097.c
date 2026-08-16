/*@
predicate is_less_than(integer a, integer b) = a < b;

logic integer add_one(integer n) = n + 1;
logic integer add_two(integer n) = n + 2;
logic integer add_three(integer n) = n + 3;

lemma calc_example_3: \forall integer n; add_one(n) <= add_three(n);
lemma calc_example_4: \forall integer n; add_one(n) <= add_three(n);
lemma example_5: \forall integer a, b, c; is_less_than(a, b) && is_less_than(b, c) ==> is_less_than(a, c);
lemma example_6: \forall integer d, e, f; is_less_than(d, e) && is_less_than(e, f) ==> is_less_than(d, f);
*/

/*@
requires n == n;
ensures \result == n + 1;
*/
int add_one(int n) {
    //@ assert n == n;
    int result = n + 1;
    //@ assert result == n + 1;
    return result;
}

/*@
requires n == n;
ensures \result == n + 2;
*/
int add_two(int n) {
    //@ assert n == n;
    int result = n + 2;
    //@ assert result == n + 2;
    return result;
}

/*@
requires n == n;
ensures \result == n + 3;
*/
int add_three(int n) {
    //@ assert n == n;
    int result = n + 3;
    //@ assert result == n + 3;
    return result;
}

/*@
requires a < b && b < c;
ensures \result == 1;
*/
int verify_chain_1(int a, int b, int c) {
    //@ assert a < b;
    //@ assert b < c;
    //@ assert a < c;
    return 1;
}

/*@
requires d < e && e < f;
ensures \result == 1;
*/
int verify_chain_2(int d, int e, int f) {
    //@ assert d < e;
    //@ assert e < f;
    //@ assert d < f;
    return 1;
}

int main() {
    return 0;
}
