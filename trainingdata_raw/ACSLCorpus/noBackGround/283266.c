#include <stdbool.h>

/*@ requires 1 <= n <= 9;
    ensures \result == (n == 3 || n == 5 || n == 7);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    bool ans = false;
    //@ assert 1 <= n <= 9;
    
    switch (n)
    {
        case 3:
        case 5:
        case 7:
            ans = true;
            break;
        default:
            ans = false;
            break;
    }
    
    //@ assert ans == (n == 3 || n == 5 || n == 7);
    return ans;
}

/*@ requires 1 <= n <= 9;
    ensures \result == (n == 3 || n == 5 || n == 7);
    assigns \nothing;
*/
bool func2(unsigned int n)
{
    bool ans = false;
    //@ assert 1 <= n <= 9;
    
    switch (n)
    {
        case 3:
        case 5:
        case 7:
            ans = true;
            break;
        default:
            ans = false;
            break;
    }
    
    //@ assert ans == (n == 3 || n == 5 || n == 7);
    return ans;
}
