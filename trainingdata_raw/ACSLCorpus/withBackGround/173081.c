#include <stdbool.h>

struct Bike {
    int tag; // 0: Mountain, 1: Road, 2: Hybrid
    int gear;
    int speed;
};

/*@
    predicate is_first_gear{L}(int gear, int speed, int tag) =
        (tag == 0 && gear == 1) ||
        (tag == 1 && gear == 1) ||
        (tag == 2 && gear == 1);

    predicate is_max_speed{L}(int gear, int speed, int tag) =
        (tag == 0 && speed == 50) ||
        (tag == 1 && speed == 60) ||
        (tag == 2 && speed == 40);
*/

/*@
    requires \valid(bike);
    requires is_first_gear(bike->gear, bike->speed, bike->tag);
    requires is_max_speed(bike->gear, bike->speed, bike->tag);
    ensures \result == true;
*/
bool ride_bike(struct Bike *bike) {
    int gear;
    int speed;
    int tag;
    
    gear = bike->gear;
    speed = bike->speed;
    tag = bike->tag;
    
    //@ assert is_first_gear(gear, speed, tag);
    //@ assert is_max_speed(gear, speed, tag);
    
    return true;
}

int main() {
    return 0;
}
