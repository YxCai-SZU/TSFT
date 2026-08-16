#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result >= 0 && \result == ((((l) * (l) * (l))) / 27);
*/
int64_t func(uint32_t l)
{
    // Variable declarations at top of scope
    int64_t l_cubed;
    int64_t result;
    uint32_t count;
    
    //@ assert l * l <= 1000000;
    
    l_cubed = (int64_t)(l * l * l);
    result = 0;
    count = 0;
    
    /*@
        loop invariant 0 <= l_cubed <= 1000000000;
        loop invariant 0 <= count <= 37037037;
        loop invariant l_cubed == ((l) * (l) * (l)) - count * 27;
        loop assigns l_cubed, count;
        loop variant l_cubed;
    */
    while (l_cubed >= 27) {
        l_cubed -= 27;
        count += 1;
    }
    
    result = (int64_t)count;
    return result;
}

int main() {
    return 0;
}
