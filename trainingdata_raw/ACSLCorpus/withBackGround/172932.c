/*@
predicate strictly_monotonic(integer a, integer b, integer c) =
    a < b && b < c;
*/

/*@
lemma prove_strictly_monotonic:
    \forall integer a, b, c; strictly_monotonic(a, b, c) ==> strictly_monotonic(a, b, c);
*/

int main() {
    int a;
    int b;
    int c;
    
    a = 1;
    b = 2;
    c = 3;
    
    //@ assert strictly_monotonic(a, b, c);
    
    return 0;
}
