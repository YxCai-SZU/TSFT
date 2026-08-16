#include <stdint.h>
#include <limits.h>

struct Order {
    uint32_t value;
};

/*@
  requires \valid(o);
  assigns o->value;
  ensures o->value == \old(o->value) - 1 || o->value == \old(o->value);
  ensures o->value <= \old(o->value);
*/
void decrement(struct Order *o) {
    uint32_t old_value;
    old_value = o->value;
    
    if (o->value > 0) {
        //@ assert o->value > 0 && o->value <= UINT32_MAX;
        uint32_t new_value;
        new_value = o->value - 1;
        o->value = new_value;
    }
}

/*@ assigns \nothing; */
int main() {
    return 0;
}
