/*@
    requires num >= 0;
    ensures \result > num;
*/
int incr(int num) {
    int result;
    //@ assert num >= 0;
    result = num + 1;
    //@ assert result > num;
    return result;
}

/*@
    requires num >= 0;
    ensures \result == 2 * num;
*/
int double_incr(int num) {
    int result;
    //@ assert num >= 0;
    result = num + num;
    //@ assert result == 2 * num;
    return result;
}

/*@
    requires num >= 0;
    ensures \result == 3 * num;
*/
int triple_incr(int num) {
    int result;
    //@ assert num >= 0;
    result = num + num + num;
    //@ assert result == 3 * num;
    return result;
}

/*@
    requires x <= y;
    ensures \result <= y + y;
*/
int calc_example_3(int x, int y) {
    int result;
    //@ assert x <= y;
    result = x + y;
    //@ assert result <= y + y;
    return result;
}

/*@
    requires n >= 1;
    ensures \result == 0;
*/
int exists_even_num(int n) {
    int result;
    //@ assert n >= 1;
    result = (n * 2) % 2;
    //@ assert result == 0;
    return result;
}

int main() {
    return 0;
}
