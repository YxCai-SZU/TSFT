#include <stdint.h>

/*@
    requires ((l) >= 0) && ((l) <= 1290);
    ensures \result == l * l * l;
    assigns \nothing;
*/
int32_t volume_cube(int32_t l)
{
    //@ assert ((l) >= 0) && ((l) <= 1290);
    //@ assert ((l) * (l) <= 1290 * 1290);
    //@ assert ((l) * (l) * (l) <= 1290 * 1290 * 1290);
    
    return l * l * l;
}

int main()
{
    int32_t side_length = 5;
    int32_t volume = volume_cube(side_length);
    //@ assert volume == 5 * 5 * 5;
    return 0;
}
