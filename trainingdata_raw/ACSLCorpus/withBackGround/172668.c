#include <stdbool.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 3;
    
    logic integer mod2(integer x) = x % 2;
    
    lemma mod2_range: \forall integer x; 0 <= x <= 9 ==> 0 <= mod2(x) <= 1;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (mod2(a * b) != 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at top of scope
    unsigned long long product;
    bool is_odd = false;
    unsigned long long temp;
    
    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    
    product = a * b;
    //@ assert 1 <= product && product <= 9;
    
    temp = product;
    
    /*@
        loop invariant 0 <= temp <= product;
        loop invariant mod2(temp) == mod2(product);
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
    }
    
    //@ assert 0 <= temp <= 1;
    //@ assert mod2(temp) == mod2(product);
    
    if (temp == 1) {
        is_odd = true;
    }
    
    //@ assert is_odd == (mod2(product) != 0);
    return is_odd;
}

int main() {
    return 0;
}
