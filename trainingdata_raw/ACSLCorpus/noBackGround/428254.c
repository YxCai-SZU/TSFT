/*@
    requires width >= 0 && height >= 0 && width + height <= 1000;
    ensures \result == (2 * ((width) + (height)));
    ensures \result >= 0;
*/
int compute_perimeter(int width, int height) {
    int result;
    //@ assert width + height >= 0;
    result = 2 * (width + height);
    //@ assert result == (2 * ((width) + (height)));
    //@ assert result >= 0;
    return result;
}

int main(void) {
    int p;
    p = compute_perimeter(10, 20);
    //@ assert p >= 0;
    return 0;
}
