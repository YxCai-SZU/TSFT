#include <limits.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result >= 0;
    ensures \result <= ((n) * (a));
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    // Variable declarations at top of scope
    int ans;
    int temp_b;
    
    // Precondition verification
    //@ assert (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    
    //@ assert ((n) * (a)) <= 1000;
    
    ans = n * a;
    temp_b = b;
    
    /*@
        loop invariant 1 <= n <= 20;
        loop invariant 1 <= a <= 50;
        loop invariant 1 <= b <= 50;
        loop invariant 0 <= temp_b <= b;
        loop invariant ans >= 0;
        loop invariant ans <= ((n) * (a));
        loop invariant ans == ((n) * (a)) - (b - temp_b);
        loop assigns temp_b, ans;
        loop variant temp_b;
    */
    while (temp_b >= 1)
    {
        temp_b -= 1;
        ans -= 1;
        
        //@ assert ans == ((n) * (a)) - (b - temp_b);
        
        if (ans < 0)
        {
            ans = 0;
            break;
        }
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= ((n) * (a));
    
    return ans;
}

int main()
{
    return 0;
}
