/*@
    predicate is_between(integer a, integer b, integer c) = a <= b && b <= c;
    predicate all_between(integer a, integer b, integer c, integer d) = 
        is_between(a, b, c) && is_between(b, c, d);
    predicate strictly_increasing(integer a, integer b, integer c, integer d) = 
        a < b && b < c && c < d;
    predicate non_decreasing(integer a, integer b, integer c, integer d) = 
        a <= b && b <= c && c <= d;
    
    lemma example_proof:
        \forall integer a, b, c, d;
            all_between(a, b, c, d) &&
            strictly_increasing(a, b, c, d) &&
            non_decreasing(a, b, c, d) ==>
            a <= d;
*/

int main() {
    int a;
    int b;
    int c;
    int d;
    
    return 0;
}
