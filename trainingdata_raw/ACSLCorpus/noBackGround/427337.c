/*@
requires 1 <= a <= 100;
requires 1 <= b <= 100;
requires 1 <= c <= 100;
ensures \result == (((a) < (c) && (c) < (b)) ? 1 : (((a) > (c) && (c) > (b)) ? 1 : 0));
assigns \nothing;
*/
int func(int a, int b, int c) {
    int result;
    //@ assert ((1) != (2) && (2) != (3) && (1) != (3));
    //@ assert !((1) != (1) && (1) != (2) && (1) != (2));
    result = (a < c && c < b) || (a > c && c > b);
    return result;
}
