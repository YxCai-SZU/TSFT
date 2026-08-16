/*@
requires x >= 0 && y >= 0;
ensures \result == x + y;
*/
int add_non_negative(int x, int y) {
    //@ assert x >= 0 && y >= 0;
    int result = x + y;
    //@ assert result >= x && result >= y;
    return result;
}

int main() {
    return 0;
}
