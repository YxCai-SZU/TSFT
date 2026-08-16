/*@
requires x >= 0 && y >= 0;
ensures \result == (((x) > (y) ? (x) : (y)) >= x && ((x) > (y) ? (x) : (y)) >= y);
*/
int test_func(int x, int y) {
    int result;
    //@ assert ((x) > (y) ? (x) : (y)) >= x;
    //@ assert ((x) > (y) ? (x) : (y)) >= y;
    result = 1;
    return result;
}

int main() {
    return 0;
}
