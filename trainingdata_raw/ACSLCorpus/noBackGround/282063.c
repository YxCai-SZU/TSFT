/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
    ensures \result >= 1;
*/
int func(int a, int b, int c, int d)
{
    int max_val;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    max_val = a * c;

    //@ assert 1 <= b * c <= 10000;
    if (b * c > max_val) {
        max_val = b * c;
    }

    //@ assert 1 <= a * d <= 10000;
    if (a * d > max_val) {
        max_val = a * d;
    }

    //@ assert 1 <= b * d <= 10000;
    if (b * d > max_val) {
        max_val = b * d;
    }

    //@ assert max_val == a * c || max_val == a * d || max_val == b * c || max_val == b * d;
    return max_val;
}

int main()
{
    return 0;
}
