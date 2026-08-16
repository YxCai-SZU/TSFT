/*@
    predicate range_intersection(integer a, integer b, integer c, integer d) =
        a <= b && c <= d;
 */

/*@
    lemma calc_example_i:
        \forall integer a, b;
            a <= b ==> a + 1 <= b + 1;
 */

/*@
    lemma verify_range_intersection:
        \forall integer a, b, c, d;
            a == 2 && b == 5 && c == 3 && d == 7 ==> range_intersection(a, b, c, d);
 */

int main() {
    int a;
    int b;
    int c;
    int d;
    
    a = 2;
    b = 5;
    c = 3;
    d = 7;
    
    //@ assert range_intersection(a, b, c, d);
    
    return 0;
}
