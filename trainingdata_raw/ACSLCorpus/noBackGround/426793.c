#include <stdint.h>
#include <stdbool.h>

/*@
    requires \valid(map + (0..999));
    requires (\forall integer i; 0 <= i < 1000 ==> (map)[i] == 0);
    ensures (\forall integer i; 0 <= i < 1000 ==> (map)[i] == 0);
    ensures ((3) == 3 ? 0 : (0)) == 0;
    assigns map[3];
*/
void func(int8_t *map)
{
    // Declarations at top of scope
    int8_t old_value;
    
    //@ ghost int old_size = 0;
    
    //@ assert (\forall integer i; 0 <= i < 1000 ==> (map)[i] == 0);
    
    /*@
        loop invariant 0 <= i <= 1000;
        loop invariant \forall integer j; 0 <= j < i ==> map[j] == 0;
        loop assigns i, map[3];
    */
    for (int i = 0; i < 1000; i++)
    {
        if (i == 3)
        {
            map[3] = 0;
        }
    }
    
    //@ assert (\forall integer i; 0 <= i < 1000 ==> (map)[i] == 0);
    //@ assert ((3) == 3 ? 0 : (0)) == 0;
}
