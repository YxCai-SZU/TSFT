/*@
    predicate less_than_five(integer x) = x < 5;
    predicate less_than_six(integer x) = x < 6;
    predicate less_than_ten(integer x) = x < 10;
    predicate greater_than_one(integer x) = x >= 1;
    predicate sum_less_than_ten(integer x, integer y) = x + y <= 10;
*/

/*@
    lemma calc_example_t: \forall integer x; less_than_five(x) ==> less_than_six(x + 1);
    lemma calc_example_t2: \forall integer x, integer y; less_than_five(x) && less_than_five(y) ==> less_than_ten(x + y);
    lemma calc_example_t3: \forall integer x, integer y; greater_than_one(x) && greater_than_one(y) && sum_less_than_ten(x, y) ==> less_than_ten(x);
*/

int main() {
    int x;
    int y;
    
    //@ assert \true;
    
    return 0;
}
