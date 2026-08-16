/*@
    requires (1 <= (x) && (x) <= 1000);
    ensures \result >= 0;
    ensures \result * 3 <= x;
    ensures x < (\result + 1) * 3;
    assigns \nothing;
*/
int func(int x)
{
    int ans = 0;
    int temp_x = x;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant ans >= 0;
        loop invariant ans <= ((x) / 3);
        loop invariant x == temp_x + 3 * ans;
        loop assigns temp_x, ans;
    */
    while (temp_x >= 3)
    {
        //@ assert temp_x >= 3;
        temp_x -= 3;
        ans += 1;
        //@ assert x == temp_x + 3 * ans;
    }
    
    //@ assert ans >= 0;
    //@ assert ans * 3 <= x;
    //@ assert x < (ans + 1) * 3;
    
    return ans;
}
