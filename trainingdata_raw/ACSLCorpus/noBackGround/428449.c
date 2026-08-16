#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result == true <==> (n * a) >= b;
    ensures \result == false <==> (n * a) < b;
*/
bool func(int n, int a, int b)
{
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    
    int product;
    
    //@ ghost int original_n = n;
    //@ ghost int original_a = a;
    
    //@ assert ((original_n) * (original_a)) <= 1000;
    
    product = n * a;
    
    //@ assert product == ((original_n) * (original_a));
    
    if (product >= b)
    {
        //@ assert ((original_n) * (original_a)) >= b;
        return true;
    }
    else
    {
        //@ assert ((original_n) * (original_a)) < b;
        return false;
    }
}
