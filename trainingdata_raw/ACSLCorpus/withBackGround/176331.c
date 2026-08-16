/*@
    predicate le_plus_one(integer a, integer b) = a <= b ==> a + 1 <= b + 1;
    predicate le_plus_two(integer a, integer b) = a <= b ==> a + 2 <= b + 2;
    predicate lt_minus_one(integer a, integer b) = a < b ==> a - 1 < b - 1;
    predicate lt_minus_two(integer a, integer b) = a < b ==> a - 2 < b - 2;
*/

/*@
    lemma calc_example_i: \forall integer a, b; a <= b ==> a + 1 <= b + 1;
    lemma calc_example_ii: \forall integer a, b; a <= b ==> a + 2 <= b + 2;
    lemma calc_example_v: \forall integer a, b; a < b ==> a - 1 < b - 1;
    lemma calc_example_vi: \forall integer a, b; a < b ==> a - 2 < b - 2;
*/

int main()
{
    int a;
    int b;
    
    //@ assert le_plus_one(a, b);
    //@ assert le_plus_two(a, b);
    //@ assert lt_minus_one(a, b);
    //@ assert lt_minus_two(a, b);
    
    return 0;
}
