/*@
predicate nonnegative(integer v) = v >= 0;
predicate safe_addition(integer x, integer y, integer z) =
    x + y + z <= 2147483647;

lemma add_assoc:
    \forall integer x, y, z;
        nonnegative(x) && nonnegative(y) && nonnegative(z) && safe_addition(x, y, z) ==>
        (x + y) + z == x + (y + z);

lemma add_comm:
    \forall integer x, y;
        nonnegative(x) && nonnegative(y) && x + y <= 2147483647 ==>
        x + y == y + x;
*/

/*@
    requires x >= 0 && y >= 0 && z >= 0;
    requires (long long)x + (long long)y + (long long)z <= 2147483647;
    ensures \result == x + y + z;
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    //@ assert (long long)x + (long long)y + (long long)z <= 2147483647;
    //@ assert (long long)x + (long long)y <= 2147483647;
    
    int sum = x + y + z;
    return sum;
}

int main(void)
{
    return 0;
}
