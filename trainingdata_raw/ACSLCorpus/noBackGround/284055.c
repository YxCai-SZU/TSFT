#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == n * n;
    assigns \nothing;
*/
int func(int n)
{
    int result;
    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 10000;
    result = n * n;
    return result;
}

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> a > b;
    assigns \nothing;
*/
bool func2(unsigned int a, unsigned int b)
{
    bool result;
    if (a > b)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    return result;
}

/*@
    requires 1 <= x <= 100;
    ensures \result == x * 2;
    assigns \nothing;
*/
int func3(int x)
{
    int result;
    result = x * 2;
    return result;
}

int main()
{
    int phone_brand = 0;
    unsigned int phone_storage = 256;
    int watch_brand = 2;
    unsigned int watch_battery_life = 30;
    
    //@ assert ((phone_brand) == 0 && (phone_storage) > 128);
    //@ assert ((watch_brand) == 2 && (watch_battery_life) > 24);
    
    return 0;
}
