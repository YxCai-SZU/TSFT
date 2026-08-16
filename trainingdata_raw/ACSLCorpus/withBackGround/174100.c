/*@
    predicate sorted(int *arr, integer n) =
        \forall integer i; 0 <= i < n - 1 ==> arr[i] <= arr[i + 1];
*/

/*@
    lemma calc_multistep_example_2:
        \forall integer a, b, c, d;
            a <= b && b <= c && c <= d ==> a <= d;
*/

/*@
    lemma calc_multistep_example_3:
        \forall integer a, b, c;
            a <= b && b <= c ==> a <= c;
*/

/*@
    lemma calc_multistep_example_4:
        \forall integer a, b, c, d;
            a <= b && b <= c && c <= d ==> a <= d;
*/

/*@
    requires n > 0;
    requires \valid(arr + (0 .. n-1));
    assigns \nothing;
    ensures \result == 1 <==> sorted(arr, n);
    ensures \result == 0 <==> !sorted(arr, n);
*/
int is_sorted(int *arr, int n) {
    int i;
    int result;

    result = 1;
    i = 0;

    /*@
        loop invariant 0 <= i <= n - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= arr[j + 1];
        loop invariant result == 1 <==> (\forall integer j; 0 <= j < i ==> arr[j] <= arr[j + 1]);
        loop assigns i, result;
    */
    while (i < n - 1) {
        //@ assert i >= 0 && i < n - 1;
        if (arr[i] > arr[i + 1]) {
            result = 0;
            break;
        }
        i = i + 1;
    }

    return result;
}

int main() {
    return 0;
}
