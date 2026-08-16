/*@
    requires \valid(arr + (0..n-1));
    requires n >= 0;
    requires (\forall integer i; 0 <= i < (n) ==> (arr)[i] == (arr)[(n) - 1 - i]);
    ensures (\forall integer i; 0 <= i < (n) ==> (arr)[i] == (arr)[(n) - 1 - i]);
*/
void is_palindrome_proof(int *arr, int n) {
    //@ assert n >= 0;
    //@ assert (\forall integer i; 0 <= i < (n) ==> (arr)[i] == (arr)[(n) - 1 - i]);
}

int main() {
    return 0;
}
