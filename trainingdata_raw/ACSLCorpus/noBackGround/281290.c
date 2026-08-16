#include <stdint.h>

/*@
  requires ((x) <= 8 && (y) <= 8 && (z) <= 1000);
  ensures ((x) * (y) <= 64 && (z) <= 1000);
*/
void example_product_condition(uint32_t x, uint32_t y, uint32_t z) {
    //@ assert x <= 8;
    //@ assert y <= 8;
    //@ assert z <= 1000;
    //@ assert x * y <= 64;
    //@ assert z <= 1000;
}

/*@
  requires ((x) <= 8 && (y) <= 8 && (z) <= 1000);
  ensures ((x) * ((y) + (z)) == (x) * (y) + (x) * (z));
*/
void distributive_property(uint32_t x, uint32_t y, uint32_t z) {
    //@ assert y + z <= 1008;
    //@ assert x * (y + z) <= 8064;
    //@ assert x * y + x * z <= 8064;
    //@ assert x * (y + z) == x * y + x * z;
}

/*@
  requires ((x) <= 8 && (y) <= 8 && (z) <= 1000);
  ensures ((x) * (y) <= (z) + 100);
*/
void complex_property(uint32_t x, uint32_t y, uint32_t z) {
    //@ assert x * y <= 64;
    //@ assert 64 <= z + 100;
    //@ assert x * y <= z + 100;
}

int main() {
    return 0;
}
