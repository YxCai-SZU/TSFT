#include <stdint.h>
#include <stdbool.h>

/*@
requires
    \valid(map) &&
    ((3) >= 0 && (3) <= 65535 &&
    (code) >= -2147483648 && (code) <= 2147483647 &&
    (points) >= 0 && (points) <= 65535);
ensures
    (\exists integer i; (map)[i] == (3) && (map)[i+1] == (code));
*/
void is_circuit_event(int *map, int32_t code, uint16_t points)
{
    uint16_t id = 3;
    int32_t event_code = code;
    uint16_t event_points = points;
    
    //@ assert ((id) >= 0 && (id) <= 65535 &&     (event_code) >= -2147483648 && (event_code) <= 2147483647 &&     (event_points) >= 0 && (event_points) <= 65535);
    
    map[0] = (int)id;
    map[1] = event_code;
    
    //@ assert (\exists integer i; (map)[i] == (id) && (map)[i+1] == (event_code));
}
