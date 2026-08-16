/*@
    predicate is_even(integer x) = x % 2 == 0;
    logic integer product_mod2(integer a, integer b) = (a * b) % 2;
    
    lemma product_bound: \forall integer a, b; 1 <= a <= 10000 && 1 <= b <= 10000 ==> a * b <= 100000000;
    lemma mod_preserved: \forall integer x, y; x >= 0 && y >= 2 && x <= y ==> (x - 2) % 2 == x % 2;
*/

#include <stdbool.h>


bool func(int a, int b)
{
    int product;
    int temp;
    
    //@ assert a * b <= 100000000;
    product = a * b;
    temp = product;
    
    
    while (temp >= 2)
    {
        //@ assert (temp - 2) % 2 == temp % 2;
        temp = temp - 2;
    }
    
    //@ assert temp == product % 2;
    return temp == 0;
}
