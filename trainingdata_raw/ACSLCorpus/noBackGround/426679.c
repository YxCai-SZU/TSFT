/*@
    requires \valid(arr + (0..len-1));
    requires arr[i] == arr[j];
    ensures arr[j] == arr[i];
*/
void lemma_array_eq(int *arr, int len, int i, int j) {
    //@ assert arr[i] == arr[j];
}

/*@
    requires \valid(arr + (0..len-1));
    requires arr[i] == arr[j];
    ensures arr[j] == arr[i];
*/
void calc_example_i(int *arr, int len, int i, int j) {
    //@ assert arr[i] == arr[j];
}

/*@
    requires \valid(arr + (0..len-1));
    ensures ((len)) == ((len));
*/
void proof_array_length(int *arr, int len) {
    //@ assert ((len)) == ((len));
}

/*@
    ensures 5 == 5;
*/
void proof_constant() {
    //@ assert 5 == 5;
}

int main() {
    return 0;
}
