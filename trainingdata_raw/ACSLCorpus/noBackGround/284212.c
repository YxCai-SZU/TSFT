/*@
    requires (0 <= (a) <= 9 && 0 <= (b) <= 9);
    ensures \result >= 0;
    ensures \result <= a + b + 1;
*/
int func(int a, int b) {
    int max;
    int min;
    int result;

    //@ assert (0 <= (a) <= 9 && 0 <= (b) <= 9);
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    //@ assert max == ((a) > (b) ? (a) : (b));

    if (a < b) {
        min = a;
    } else {
        min = b;
    }
    //@ assert min == ((a) < (b) ? (a) : (b));

    if (max - min >= 2) {
        //@ assert max - min >= 2;
        result = 1;
    } else {
        //@ assert max - min < 2;
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result <= a + b + 1;
    return result;
}
