#include <stdint.h>

/*@
    predicate is_square_pre(uint32_t n) = n < 1000;
    
    predicate is_square_post(uint32_t n, uint32_t ret) = 
        ret == n * n && ret >= n;
*/

/*@
    requires is_square_pre(n);
    ensures is_square_post(n, \result);
    assigns \nothing;
*/
uint32_t is_square(uint32_t n)
{
    uint32_t ret;
    
    //@ assert n * n < 1000 * 1000;
    //@ assert n * n >= n;
    
    ret = n * n;
    
    //@ assert ret == n * n;
    //@ assert ret >= n;
    
    return ret;
}

int main()
{
    return 0;
}
