#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (6 * (r));
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3;
    int circumference;
    
    //@ assert 1 <= r && r <= 100;
    circumference = 2 * r * pi;
    
    //@ assert circumference == 6 * r;
    return circumference;
}

/*@
    requires (1 <= (r) && (r) <= 100) && (1 <= (h) && (h) <= 100);
    ensures \result == (3 * (r) * (r) * (h));
    assigns \nothing;
*/
int volume_cylinder(int r, int h)
{
    int pi = 3;
    int volume;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 1 <= h && h <= 100;
    
    //@ assert 1 <= r * r <= 10000;
    //@ assert 1 <= pi * r * r <= 30000;
    //@ assert 1 <= pi * r * r * h <= 3000000;
    
    volume = pi * r * r * h;
    
    //@ assert volume == 3 * r * r * h;
    return volume;
}
