/*@
    predicate equal_mult(integer x, integer y) = y == x * 2;
    predicate ge_sum(integer x, integer y) = y >= x + x;
    predicate equal_plus_one(integer x, integer y) = x == y + 1;
    predicate equal_minus_one(integer x, integer y) = x == y - 1;
    predicate equal_self_plus_zero(integer x) = x == x + 0;

    lemma calc_example_8: \forall integer x, y; equal_mult(x, y) ==> ge_sum(x, y);
    lemma lemma_array_eq: \forall int *arr, integer i, integer j; (0 <= i && 0 <= j) ==> (arr[i] == arr[j] ==> arr[j] == arr[i]);
    lemma calc_example_9: \forall integer x, y; equal_mult(x, y) ==> ge_sum(x, y);
    lemma lemma_addition: \forall integer x, y; equal_plus_one(x, y) ==> y == x - 1;
    lemma lemma_subtraction: \forall integer x, y; equal_minus_one(x, y) ==> y == x + 1;
    lemma lemma_x_plus_0: \forall integer x; equal_self_plus_zero(x) ==> x + 0 == x;
*/

/*@
    requires equal_mult(x, y);
    ensures ge_sum(x, y);
*/
void calc_example_8(int x, int y) {
    //@ assert y == x * 2;
}

/*@
    requires \valid_read(arr + (0 .. 0));
    requires 0 <= i && 0 <= j;
    requires arr[i] == arr[j];
    ensures arr[j] == arr[i];
*/
void lemma_array_eq(int *arr, int i, int j) {
    //@ assert arr[i] == arr[j];
}

/*@
    requires equal_mult(x, y);
    ensures ge_sum(x, y);
*/
void calc_example_9(int x, int y) {
    //@ assert y == x * 2;
}

/*@
    requires equal_plus_one(x, y);
    ensures y == x - 1;
*/
void lemma_addition(int x, int y) {
    //@ assert x == y + 1;
}

/*@
    requires equal_minus_one(x, y);
    ensures y == x + 1;
*/
void lemma_subtraction(int x, int y) {
    //@ assert x == y - 1;
}

/*@
    requires equal_self_plus_zero(x);
    ensures x + 0 == x;
*/
void lemma_x_plus_0(int x) {
    //@ assert x == x + 0;
}

int main() {
    return 0;
}
