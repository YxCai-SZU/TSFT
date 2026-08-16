/*@
requires 1 <= a <= 9;
requires 1 <= b <= 9;
requires 1 <= c <= 9;
ensures \result == 1 <==> (((a) == (b) && (b) != (c)) ||
    ((b) == (c) && (c) != (a)) ||
    ((c) == (a) && (a) != (b)));
assigns \nothing;
*/
int func(unsigned int a, unsigned int b, unsigned int c)
{
    int result = 0;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    if (a == b && a != c) {
        result = 1;
    } else if (b == c && b != a) {
        result = 1;
    } else if (c == a && c != b) {
        result = 1;
    }

    //@ assert result == 1 <==> (((a) == (b) && (b) != (c)) ||     ((b) == (c) && (c) != (a)) ||     ((c) == (a) && (a) != (b)));

    return result;
}
