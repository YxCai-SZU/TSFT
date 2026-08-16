/*@
    requires (0 <= (X) <= 100000);
    ensures \result >= 0;
    ensures \result == (((X) / 500) * 1000 + (((X) % 500) / 5) * 5);
*/
int func(int X)
{
    int money;
    int X_remaining;
    int five_hundred_yen;
    int five_yen;
    
    money = 0;
    X_remaining = X;
    five_hundred_yen = 0;
    
    /*@
        loop invariant 0 <= X_remaining <= 100000;
        loop invariant five_hundred_yen >= 0;
        loop invariant X_remaining == X - 500 * five_hundred_yen;
        loop assigns X_remaining, five_hundred_yen;
    */
    while (X_remaining >= 500)
    {
        //@ assert X_remaining >= 500;
        X_remaining -= 500;
        five_hundred_yen += 1;
    }
    
    five_yen = 0;
    
    /*@
        loop invariant 0 <= X_remaining <= 100000;
        loop invariant five_hundred_yen >= 0;
        loop invariant five_yen >= 0;
        loop invariant X_remaining == X - 500 * five_hundred_yen - 5 * five_yen;
        loop assigns X_remaining, five_yen;
    */
    while (X_remaining >= 5)
    {
        //@ assert X_remaining >= 5;
        X_remaining -= 5;
        five_yen += 1;
    }
    
    money = five_hundred_yen * 1000 + five_yen * 5;
    
    //@ assert money >= 0;
    //@ assert money == (((X) / 500) * 1000 + (((X) % 500) / 5) * 5);
    
    return money;
}

int main()
{
    return 0;
}
