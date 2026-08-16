/*@
    predicate mod_property(integer x, integer y) = y != 0 ==> (x % y) % y == x % y;
    
    lemma mul_commutative: \forall integer a, b; a * b == b * a;
    lemma mul_associative: \forall integer a, b, c; a * (b * c) == (a * b) * c;
    lemma mul_distributive_add: \forall integer a, b, c; a * (b + c) == a * b + a * c;
*/

int main() {
    return 0;
}
