/*@
    predicate valid_range(integer x) = 1 <= x && x <= 9;
    predicate product_bound(integer x, integer y) = x * y <= 81;
    predicate less_than_succ(integer a, integer b) = a < b + 1;
*/

/*@
    lemma calc_example_5: \forall integer x, y; valid_range(x) && valid_range(y) ==> product_bound(x, y);
    lemma calc_example_6: \forall integer a, b; a < b ==> less_than_succ(a, b);
    lemma calc_example_7: \forall integer a, b; a < b ==> less_than_succ(a, b);
    lemma calc_example_8: \forall integer a, b; a < b ==> less_than_succ(a, b);
    lemma calc_example_9: \forall integer a, b; a < b ==> less_than_succ(a, b);
*/

int main()
{
    int x;
    int y;
    int a;
    int b;
    
    //@ assert valid_range(x) && valid_range(y) ==> product_bound(x, y);
    //@ assert a < b ==> less_than_succ(a, b);
    
    return 0;
}
