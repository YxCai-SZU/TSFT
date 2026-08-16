/*@
    predicate example_5_cond(integer s, integer t) = s * 3 == t;
    predicate example_5_post(integer s, integer t) = s <= t / 3;
    predicate example_6_cond(integer a, integer b, integer c) = a + b == c;
    predicate example_6_post(integer a, integer b, integer c) = a <= c - b;
    predicate example_7_cond(integer x, integer y) = x * 2 == y;
    predicate example_7_post(integer x, integer y) = x <= y / 2;
*/

/*@
    lemma calc_example_5: \forall integer s, t; example_5_cond(s, t) ==> example_5_post(s, t);
    lemma calc_example_6: \forall integer a, b, c; example_6_cond(a, b, c) ==> example_6_post(a, b, c);
    lemma calc_example_7: \forall integer x, y; example_7_cond(x, y) ==> example_7_post(x, y);
*/

/*@
    lemma example_5_test: \forall integer s, t; example_5_cond(s, t) ==> example_5_post(s, t);
    lemma example_6_test: \forall integer a, b, c; example_6_cond(a, b, c) ==> example_6_post(a, b, c);
    lemma example_7_test: \forall integer x, y; example_7_cond(x, y) ==> example_7_post(x, y);
*/

int main() {
    int s;
    int t;
    int a;
    int b;
    int c;
    int x;
    int y;
    
    //@ assert \true;
    
    return 0;
}
