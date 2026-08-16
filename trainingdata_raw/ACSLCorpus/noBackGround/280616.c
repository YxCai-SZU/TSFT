/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == 1 <==> (500 * k) >= x;
    ensures \result == 0 <==> (500 * k) < x;
*/
int func(int k, int x)
{
    // Variable declarations at scope top
    int en;
    int en_val;
    int result;

    en = 500;
    
    //@ assert 500 <= 100 * 5;
    //@ assert 100 * 5 <= 500;
    //@ assert 500 <= 100 * 5;
    //@ assert 100 * 5 <= 100 * 5;
    
    en_val = k * en;
    result = (en_val >= x) ? 1 : 0;
    
    return result;
}

int main()
{
    // Main function intentionally left empty
    return 0;
}
