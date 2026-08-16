/*@
predicate associative_addition_holds(integer x, integer y, integer z) =
    (x + y) + z == x + (y + z);

predicate multiplication_zero_holds(integer x) =
    x * 0 == 0;

predicate commutative_addition_holds(integer x, integer y) =
    x + y == y + x;

predicate absorption_holds(integer x, integer y) =
    x + (y + y) == y + (x + y);

lemma lemma_associative_addition:
    \forall integer x, y, z; associative_addition_holds(x, y, z);

lemma lemma_multiplication_zero:
    \forall integer x; multiplication_zero_holds(x);

lemma lemma_commutive_addition:
    \forall integer x, y; commutative_addition_holds(x, y);

lemma lemma_absorption:
    \forall integer x, y;
        commutative_addition_holds(x, y) &&
        associative_addition_holds(x, y, y) ==>
        absorption_holds(x, y);
*/

/*@
    requires associative_addition_holds(x, y, z);
    requires multiplication_zero_holds(x);
    ensures \result == x * y + x * z;
*/
int distributive_addition(int x, int y, int z) {
    //@ assert associative_addition_holds(x, y, z);
    //@ assert multiplication_zero_holds(x);
    
    int result = x * (y + z);
    
    //@ assert result == x * y + x * z;
    return result;
}

int main() {
    int x = 5;
    int y = 3;
    int z = 2;
    
    //@ assert associative_addition_holds(x, y, z);
    //@ assert multiplication_zero_holds(x);
    //@ assert commutative_addition_holds(x, y);
    //@ assert associative_addition_holds(x, y, y);
    //@ assert absorption_holds(x, y);
    
    int result = distributive_addition(x, y, z);
    return 0;
}
