#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == (((a) * (b)) % 2 == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    // Variable declarations at top of scope
    int c;
    bool is_even;
    int abs_c;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    //@ assert 1 <= ((a) * (b)) <= 100000000;
    c = a * b;
    
    is_even = true;
    abs_c = (c < 0) ? -c : c;
    
    /*@
        loop invariant 0 <= abs_c <= ((a) * (b));
        loop invariant (c % 2 == 0) ==> is_even;
        loop invariant abs_c % 2 == c % 2;
        loop invariant (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
        loop assigns abs_c, is_even;
        loop variant abs_c;
    */
    while (abs_c > 0)
    {
        if (abs_c == 1)
        {
            is_even = false;
            break;
        }
        
        //@ assert abs_c >= 2;
        abs_c -= 2;
    }
    
    //@ assert is_even ==> (((a) * (b)) % 2 == 0);
    return is_even;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
