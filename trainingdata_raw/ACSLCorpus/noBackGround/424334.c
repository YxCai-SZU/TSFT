/*@
    requires 0 <= x <= 100 && 0 <= y <= 100;
    ensures \result == ((x) * (y));
*/
int func(int x, int y)
{
    //@ assert 0 <= x && x <= 100;
    //@ assert 0 <= y && y <= 100;
    //@ assert 0 <= ((x) * (y)) && ((x) * (y)) <= 10000;
    int result;
    result = x * y;
    //@ assert result == ((x) * (y));
    return result;
}

int main() {
    return 0;
}
