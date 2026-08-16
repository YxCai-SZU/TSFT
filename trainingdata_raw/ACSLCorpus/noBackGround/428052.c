/*@
    requires \valid(s + (0..2));
    ensures \true;
*/
void calc_example_i(int *s) {
    //@ assert ((3)) >= 3;
    //@ assert ((2) - (1)) == ((1) - (0));
}

/*@
    requires a + b + b == 2 * b + a;
    ensures \result == 0;
*/
int calc_example_ii(int a, int b) {
    int result = 0;
    //@ assert a + b + b == 2 * b + a;
    return result;
}

/*@
    requires a + b + b + b == 3 * b + a;
    ensures \result == 0;
*/
int calc_example_iii(int a, int b) {
    int result = 0;
    //@ assert a + b + b + b == 3 * b + a;
    return result;
}

int main() {
    int arr[3] = {1, 2, 3};
    calc_example_i(arr);
    
    int x = calc_example_ii(5, 3);
    int y = calc_example_iii(5, 3);
    
    return 0;
}
