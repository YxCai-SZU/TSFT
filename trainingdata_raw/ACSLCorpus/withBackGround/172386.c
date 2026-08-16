/*@
    predicate positive(integer a) = a > 0;
    predicate positive4(integer a, integer b, integer c, integer d) = a > 0 && b > 0 && c > 0 && d > 0;
    predicate positive3(integer x, integer y, integer z) = x > 0 && y > 0 && z > 0;
    predicate positive2(integer a, integer b) = a > 0 && b > 0;

    logic integer mul4(integer a, integer b, integer c, integer d) = a * b * c * d;
    logic integer mul2(integer a, integer b) = a * b;
    logic integer add2(integer y, integer z) = y + z;
    logic integer mul3(integer x, integer y, integer z) = x * y * z;

    lemma example_3: \forall integer a, b, c, d; positive4(a, b, c, d) ==> mul4(a, b, c, d) == mul2(a, b) * mul2(c, d);
    lemma example_4: \forall integer x, y, z; positive3(x, y, z) ==> x * add2(y, z) == x * y + x * z;
    lemma example_5: \forall integer a, b; positive2(a, b) ==> a * b <= a * b;
    lemma example_6: \forall integer x, y, z; positive3(x, y, z) ==> x * (y * z) == (x * y) * z;
    lemma example_7: \forall integer a, b, c, d; positive4(a, b, c, d) ==> mul4(a, b, c, d) <= mul4(a, b, c, d);
    lemma example_8: \forall integer x, y, z; positive3(x, y, z) ==> x * add2(y, z) <= x * y + x * z;
    lemma example_9: \forall integer a, b; positive2(a, b) ==> a * b <= a * b;
    lemma example_10: \forall integer x, y, z; positive3(x, y, z) ==> x * (y * z) <= (x * y) * z;
*/

int main() {
    return 0;
}
