/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer func_spec(integer n) = 
        n >= 0 ? (n / 2) : 0;
    
    lemma func_lemma: 
        \forall integer n; 
        is_valid_n(n) ==> 
        0 <= func_spec(n) && func_spec(n) <= n;
*/

/*@
    requires is_valid_n(n);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n)
{
    int count = 0;
    int num = n;
    
    if (n >= 0)
    {
        /*@
            loop invariant 0 <= num <= n;
            loop invariant 0 <= count <= n / 2;
            loop invariant num == n - 2 * count;
            loop assigns num, count;
            loop variant num;
        */
        while (num >= 2)
        {
            //@ assert num >= 2;
            num -= 2;
            count += 1;
        }
        //@ assert count >= 0;
        //@ assert count <= n;
        return count;
    }
    else
    {
        return 0;
    }
}
