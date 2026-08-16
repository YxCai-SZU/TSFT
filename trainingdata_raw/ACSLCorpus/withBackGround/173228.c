/*@
    predicate non_negative(integer x) = x >= 0;
    predicate within_range(integer x) = 0 <= x && x <= 10;
    predicate ordered(integer a, integer b) = a <= b;
    predicate square_ordered(integer a, integer b) = a * a <= b * b;
*/

/*@
    lemma square_range: 
        \forall integer a, b; 
        within_range(a) && within_range(b) && ordered(a,b) ==> square_ordered(a,b);
*/

/*@
    requires 0 <= a <= b <= 10;
    ensures \result == 1;
    assigns \nothing;
*/
int square_range_proof(int a, int b) {
    //@ assert within_range(a);
    //@ assert within_range(b);
    //@ assert ordered(a,b);
    //@ assert square_ordered(a,b);
    return 1;
}

int main() {
    int a;
    int b;
    int result;
    
    a = 3;
    b = 7;
    result = square_range_proof(a, b);
    return 0;
}
