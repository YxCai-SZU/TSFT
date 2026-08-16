/*@
    logic integer max(integer x, integer y) = (x >= y) ? x : y;

    lemma max_is_max_a:
        \forall integer a, b; max(a, b) >= a;

    lemma max_is_max_b:
        \forall integer a, b; max(a, b) >= b;

    lemma max_properties:
        \forall integer a, b; max(a, b) == a || max(a, b) == b;
*/

int main() {
    //@ assert max(5, 3) >= 5;
    //@ assert max(5, 3) >= 3;
    //@ assert max(5, 3) == 5 || max(5, 3) == 3;
    
    return 0;
}
