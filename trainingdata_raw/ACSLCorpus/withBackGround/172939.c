/*@
predicate is_even_prop(integer n) =
    n >= 0 && n <= 100 ==> (n % 2 == 0 || n % 2 == 1);

lemma calc_example_9:
    \forall integer x, y; x <= y ==> x / 2 <= y / 2;

lemma is_even_lemma:
    \forall integer n; n >= 0 && n <= 100 ==> (n % 2 == 0 || n % 2 == 1);
*/

/*@
requires x <= y;
ensures \result == 1;
assigns \nothing;
*/
int calc_example_9(int x, int y) {
    //@ assert x / 2 <= y / 2;
    return 1;
}

/*@
requires n >= 0 && n <= 100;
ensures \result == 1;
assigns \nothing;
*/
int is_even(int n) {
    //@ assert n % 2 == 0 || n % 2 == 1;
    return 1;
}

int main() {
    return 0;
}
