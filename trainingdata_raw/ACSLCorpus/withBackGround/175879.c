#include <stdbool.h>

/*@ predicate is_large_truck(integer tag, integer load_capacity, integer bed_size, integer volume) =
    (tag == 0 && load_capacity > 10000) ||
    (tag == 1 && bed_size > 10) ||
    (tag == 2 && volume > 500);
*/

/*@ predicate truck_property(integer tag, integer load_capacity, integer bed_size, integer volume) =
    (tag == 0 && load_capacity > 10000) ||
    (tag == 1 && bed_size > 10) ||
    (tag == 2 && volume > 500);
*/

/*@ lemma truck_equivalence: 
    \forall integer tag, integer load_capacity, integer bed_size, integer volume;
    is_large_truck(tag, load_capacity, bed_size, volume) <==> 
    truck_property(tag, load_capacity, bed_size, volume);
*/

/*@ requires 1 <= r <= 100;
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    //@ assert 1 <= r && r <= 100;
    //@ assert r * r <= 10000;
    return r * r;
}

void test_truck(void)
{
    int semi_tag = 0;
    int semi_load = 20000;
    int pickup_tag = 1;
    int pickup_bed = 15;
    int delivery_tag = 2;
    int delivery_vol = 750;
    
    //@ assert is_large_truck(semi_tag, semi_load, 0, 0);
    //@ assert is_large_truck(pickup_tag, 0, pickup_bed, 0);
    //@ assert is_large_truck(delivery_tag, 0, 0, delivery_vol);
    
    //@ assert truck_property(semi_tag, semi_load, 0, 0);
    //@ assert truck_property(pickup_tag, 0, pickup_bed, 0);
    //@ assert truck_property(delivery_tag, 0, 0, delivery_vol);
}

int main(void)
{
    return 0;
}
