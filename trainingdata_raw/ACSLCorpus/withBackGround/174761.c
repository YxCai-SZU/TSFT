/*@
    predicate is_valid_range(integer k) = 2 <= k && k <= 100;
    
    logic integer division_by_two(integer k) = k / 2;
    
    lemma division_property:
        \forall integer k; is_valid_range(k) ==> 
            division_by_two(k) * (k - division_by_two(k)) == k / 2 * (k - k / 2);
*/

/*@
    requires is_valid_range(k);
    ensures \result == k / 2 * (k - k / 2);
*/
int func(int k)
{
    int a;
    int b;
    int temp_k;
    int count;
    int res;
    
    a = 0;
    b = 0;
    temp_k = k;
    count = 0;
    
    /*@
        loop invariant 2 <= k && k <= 100;
        loop invariant 0 <= temp_k && temp_k <= k;
        loop invariant temp_k == k - 2 * count;
        loop invariant 0 <= count && count <= k / 2;
        loop assigns temp_k, count;
    */
    while (temp_k >= 2)
    {
        temp_k -= 2;
        count += 1;
    }
    a = count;
    
    b = k - a;
    
    //@ assert a >= 0 && a <= 50;
    //@ assert b >= 0 && b <= 50;
    //@ assert a * b <= 50 * 50;
    
    res = a * b;
    return res;
}

int main()
{
    return 0;
}
