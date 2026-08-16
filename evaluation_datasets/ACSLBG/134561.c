/*@
predicate distinct_three(integer a, integer b, integer c) =
    a != b && a != c && b != c;

logic integer add_assoc(integer a, integer b, integer c) =
    (a + b) + c;

lemma associative_add:
    \forall integer a, b, c;
        add_assoc(a, b, c) == a + (b + c);

lemma no_collisions_in_1x4_range:
    \forall integer a, b, c;
        (0 <= a && a <= 3 && 0 <= b && b <= 3 && 0 <= c && c <= 3 &&
        distinct_three(a, b, c)) ==>
        distinct_three(a, b, c);
*/

int main() {
    int a;
    int b;
    int c;
    
    //@ assert distinct_three(a, b, c) ==> distinct_three(a, b, c);
    
    return 0;
}
