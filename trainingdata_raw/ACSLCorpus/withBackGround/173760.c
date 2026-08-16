/*@
    predicate pos(integer x) = x >= 1;

    lemma calc_example_6:
        \forall integer x, y;
            pos(x) && pos(y) ==> (x + y) * (x + y - 1) / 2 >= 0;
*/

/*@
    requires \valid(out);
    requires x >= 1;
    requires y >= 1;
    assigns *out;
    ensures *out == (x + y) * (x + y - 1) / 2;
    ensures *out >= 0;
*/
void compute_example(int x, int y, int *out) {
    int result;
    int sum;

    //@ assert x >= 1 && y >= 1;
    sum = x + y;
    //@ assert sum >= 2;
    //@ assert sum - 1 >= 1;
    //@ assert sum * (sum - 1) >= 0;
    result = sum * (sum - 1) / 2;
    //@ assert result >= 0;
    *out = result;
}

int main() {
    int output;
    compute_example(1, 1, &output);
    return 0;
}
