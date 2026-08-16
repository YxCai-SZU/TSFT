/*@
    requires n >= 0;
    ensures \result >= 0;
*/
int func_1_impl(int n) {
    int sum;
    //@ assert n >= 0;
    //@ assert n + n*n >= 0;
    //@ assert n*n*n >= 0;
    sum = n + n*n + n*n*n;
    //@ assert sum >= 0;
    return sum;
}

/*@
    requires x > y;
    ensures \result > 0;
*/
int func_2_impl(int x, int y) {
    int diff;
    //@ assert x > y;
    diff = x - y;
    //@ assert diff > 0;
    return diff;
}

/*@
    requires n >= 0;
    ensures \result >= 0;
*/
int func_3_impl(int n) {
    int cube;
    //@ assert n >= 0;
    //@ assert n*n >= 0;
    cube = n*n*n;
    //@ assert cube >= 0;
    return cube;
}

int main() {
    return 0;
}
