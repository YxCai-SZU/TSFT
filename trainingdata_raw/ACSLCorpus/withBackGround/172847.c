/*@
    predicate valid_range(integer x) = 1 <= x <= 9;
    predicate valid_range_plus_one(integer x) = 2 <= x <= 10;
    predicate strictly_increasing(integer a, integer b, integer c) = a < b && b < c;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == 1 <==> strictly_increasing(a, b, c);
*/
int func(int a, int b, int c)
{
    int aa;
    int bb;
    int cc;
    int result;

    a = a + 1;
    b = b + 1;
    c = c + 1;

    aa = 0;
    bb = 0;
    cc = 0;

    //@ assert valid_range_plus_one(a);
    if (a == 1) {
        aa = 1;
    } else if (a == 2) {
        aa = 2;
    } else if (a == 3) {
        aa = 3;
    } else if (a == 4) {
        aa = 4;
    } else if (a == 5) {
        aa = 5;
    } else if (a == 6) {
        aa = 6;
    } else if (a == 7) {
        aa = 7;
    } else if (a == 8) {
        aa = 8;
    } else if (a == 9) {
        aa = 9;
    } else if (a == 10) {
        aa = 10;
    }

    //@ assert valid_range_plus_one(b);
    if (b == 1) {
        bb = 1;
    } else if (b == 2) {
        bb = 2;
    } else if (b == 3) {
        bb = 3;
    } else if (b == 4) {
        bb = 4;
    } else if (b == 5) {
        bb = 5;
    } else if (b == 6) {
        bb = 6;
    } else if (b == 7) {
        bb = 7;
    } else if (b == 8) {
        bb = 8;
    } else if (b == 9) {
        bb = 9;
    } else if (b == 10) {
        bb = 10;
    }

    //@ assert valid_range_plus_one(c);
    if (c == 1) {
        cc = 1;
    } else if (c == 2) {
        cc = 2;
    } else if (c == 3) {
        cc = 3;
    } else if (c == 4) {
        cc = 4;
    } else if (c == 5) {
        cc = 5;
    } else if (c == 6) {
        cc = 6;
    } else if (c == 7) {
        cc = 7;
    } else if (c == 8) {
        cc = 8;
    } else if (c == 9) {
        cc = 9;
    } else if (c == 10) {
        cc = 10;
    }

    //@ assert aa == a;
    //@ assert bb == b;
    //@ assert cc == c;

    if (aa < bb && bb < cc) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}
