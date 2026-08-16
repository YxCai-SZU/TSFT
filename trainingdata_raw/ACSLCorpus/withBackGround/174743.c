/*@
predicate multiplication_is_distributive(integer x, integer y, integer z) =
    x * (y + z) == x * y + x * z;

predicate addition_is_commutative(integer x, integer y) =
    x + y == y + x;

predicate addition_is_associative(integer x, integer y, integer z) =
    (x + y) + z == x + (y + z);

predicate multiplication_is_associative(integer x, integer y, integer z) =
    (x * y) * z == x * (y * z);

lemma distributivity_lemma:
    \forall integer x, y, z; multiplication_is_distributive(x, y, z) ==>
        x * (y + z) == x * y + x * z;

lemma commutativity_lemma:
    \forall integer x, y; addition_is_commutative(x, y) ==>
        x + y == y + x;

lemma addition_assoc_lemma:
    \forall integer x, y, z; addition_is_associative(x, y, z) ==>
        (x + y) + z == x + (y + z);

lemma multiplication_assoc_lemma:
    \forall integer x, y, z; multiplication_is_associative(x, y, z) ==>
        (x * y) * z == x * (y * z);
*/

/*@
    requires n == 10;
    ensures \result == 50;
*/
int calc_example_6(int n)
{
    int result;
    int temp1;
    int temp2;
    
    //@ assert n == 10;
    
    temp1 = 2 + 3;
    //@ assert addition_is_associative(2, 3, 0);
    //@ assert temp1 == 5;
    
    result = n * temp1;
    //@ assert multiplication_is_associative(n, 2, 3);
    //@ assert result == 50;
    
    return result;
}

int main()
{
    return 0;
}
