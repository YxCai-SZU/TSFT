/*@
predicate mul_distributive(integer x, integer y, integer z) =
    x * (y + z) == x * y + x * z;

predicate mul_associative(integer x, integer y, integer z) =
    (x * y) * z == x * (y * z);

lemma mul_distributive_lemma:
    \forall integer x, y, z; mul_distributive(x, y, z);

lemma mul_associative_lemma:
    \forall integer x, y, z; mul_associative(x, y, z);
*/

/*@
    requires \true;
    ensures \result == 0;
*/
int main() {
    int x;
    int y;
    int z;
    int result1;
    int result2;

    //@ assert mul_distributive(x, y, z);
    //@ assert mul_associative(x, y, z);

    result1 = x * (y + z);
    result2 = x * y + x * z;
    //@ assert result1 == result2;

    result1 = (x * y) * z;
    result2 = x * (y * z);
    //@ assert result1 == result2;

    return 0;
}
