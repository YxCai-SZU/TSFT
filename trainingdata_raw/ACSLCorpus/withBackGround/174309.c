/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 100;
    
    logic integer mymin(integer x, integer y) = x <= y ? x : y;
    
    lemma min_properties:
        \forall integer x, y;
            mymin(x, y) <= x &&
            mymin(x, y) <= y &&
            (mymin(x, y) == x || mymin(x, y) == y);
    
    logic integer mymax(integer x, integer y) = x >= y ? x : y;
    
    lemma max_properties:
        \forall integer x, y;
            mymax(x, y) >= x &&
            mymax(x, y) >= y &&
            (mymax(x, y) == x || mymax(x, y) == y);
*/

/*@
    requires is_valid_range(n);
    ensures \result == n * n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 * 1 <= n * n && n * n <= 100 * 100;
    
    return n * n;
}
