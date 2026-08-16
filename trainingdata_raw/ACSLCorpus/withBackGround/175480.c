/*@
predicate division_product_prop(integer x, integer y) =
    y != 0 ==> (x / y) * y + x % y == x;

predicate mul_distributive_prop(integer x, integer y, integer z) =
    x * (y + z) == x * y + x * z;

predicate mul_commutative_prop(integer x, integer y) =
    x * y == y * x;

lemma division_product_lemma:
    \forall integer x, y; division_product_prop(x, y);

lemma mul_distributive_lemma:
    \forall integer x, y, z; mul_distributive_prop(x, y, z);

lemma mul_commutative_lemma:
    \forall integer x, y; mul_commutative_prop(x, y);
*/

int main() {
    unsigned int x;
    unsigned int y;
    unsigned int z;
    
    //@ assert division_product_prop(x, y);
    //@ assert mul_distributive_prop(x, y, z);
    //@ assert mul_commutative_prop(x, y);
    
    return 0;
}
