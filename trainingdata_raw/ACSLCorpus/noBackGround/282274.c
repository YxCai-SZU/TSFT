#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    ensures \result == ((((a) * (b)) % 2) == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top
    bool res;
    unsigned long long product;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    product = (unsigned long long)a * (unsigned long long)b;
    
    //@ assert product <= 100000000;
    
    if (product % 2 == 0) {
        res = true;
    } else {
        res = false;
    }
    
    //@ assert res == (product % 2 == 0);
    return res;
}

#ifdef TEST
#include <assert.h>

int main()
{
    // Test case 1
    unsigned int a1 = 10;
    unsigned int b1 = 20;
    bool result1 = func(a1, b1);
    //@ assert result1 == true;
    assert(result1 == true);
    
    // Test case 2
    unsigned int a2 = 11;
    unsigned int b2 = 21;
    bool result2 = func(a2, b2);
    //@ assert result2 == false;
    assert(result2 == false);
    
    return 0;
}
#endif
