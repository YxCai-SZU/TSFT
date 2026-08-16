/*@
  requires a > 0 && b > 0;
  ensures \result > a;
*/
int calc_example(int a, int b) {
    int result;
    result = a + b;

    //@ assert ((a) > 0);
    //@ assert ((b) > 0);
    //@ assert result == a + b;
    //@ assert result > a;

    return result;
}

int main() {
    int x = 5;
    int y = 3;
    int res;

    res = calc_example(x, y);
    return 0;
}
