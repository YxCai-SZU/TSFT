/*@
predicate range_a(integer a) = 1 <= a && a <= 5;
predicate range_b(integer b) = 5 <= b && b <= 10;
predicate range_c(integer c) = 10 <= c && c <= 15;
*/

/*@
lemma different_step_relations:
    \forall integer a, b, c;
        range_a(a) && range_b(b) && range_c(c) ==> a <= c;
*/

/*@
requires 1 <= a && a <= 5;
assigns \nothing;
*/
void range_a(int a) {}

/*@
requires 5 <= b && b <= 10;
assigns \nothing;
*/
void range_b(int b) {}

/*@
requires 10 <= c && c <= 15;
assigns \nothing;
*/
void range_c(int c) {}

/*@
assigns \nothing;
*/
void main() {
    int a = 3;
    int b = 7;
    int c = 12;
    
    //@ assert range_a(a);
    //@ assert range_b(b);
    //@ assert range_c(c);
    //@ assert a <= c;
}
