/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == b + c || \result == c + 1 || \result == c + a || \result == a + 1;
    ensures \result >= 0;
*/
int func(int a, int b, int c)
{
    int min_val;
    int temp_val;

    min_val = b + c;
    temp_val = c + 1;

    //@ assert min_val == b + c || min_val == c + 1;
    if (temp_val < min_val) {
        min_val = temp_val;
    }

    temp_val = c + a;
    //@ assert min_val == b + c || min_val == c + 1 || min_val == c + a;
    if (temp_val < min_val) {
        min_val = temp_val;
    }

    temp_val = a + 1;
    //@ assert min_val == b + c || min_val == c + 1 || min_val == c + a || min_val == a + 1;
    if (temp_val < min_val) {
        min_val = temp_val;
    }

    //@ assert min_val == b + c || min_val == c + 1 || min_val == c + a || min_val == a + 1;
    return min_val;
}
