#include <stdint.h>

/*@
    requires (0 <= (edge) <= 181);
    ensures \result == ((edge) * (edge) * (edge));
    assigns \nothing;
*/
uint64_t volume_cube(uint64_t edge)
{
    // Variable declarations at top of scope
    uint64_t result;
    
    //@ assert edge <= 181;
    
    //@ assert edge * edge <= 181 * 181;
    
    //@ assert edge * edge * edge <= 181 * 181 * 181;
    
    result = edge * edge * edge;
    
    //@ assert result == ((edge) * (edge) * (edge));
    
    return result;
}

int main()
{
    return 0;
}
