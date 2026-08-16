#include <stdbool.h>

enum TrafficLightTag { Green, Yellow, Red };

struct TrafficLight {
    enum TrafficLightTag tag;
    union {
        unsigned int Green_duration;
        unsigned int Yellow_duration;
        unsigned int Red_duration;
    };
};

/*@
    predicate is_safe_to_cross(struct TrafficLight e) =
        !(e.tag == Red) || e.Red_duration < 5;

    logic integer light_duration(struct TrafficLight e) =
        e.tag == Green ? e.Green_duration :
        e.tag == Yellow ? e.Yellow_duration :
        e.Red_duration;

    lemma light_duration_is_total_duration:
        \forall struct TrafficLight e;
        (e.tag == Green || e.tag == Yellow || e.tag == Red) ==>
        (light_duration(e) == e.Green_duration ||
         light_duration(e) == e.Yellow_duration ||
         light_duration(e) == e.Red_duration);

    lemma is_not_safe_to_cross_is_red:
        \forall struct TrafficLight e;
        !is_safe_to_cross(e) ==> e.tag == Red;
*/

void test_traffic_light(void)
{
    struct TrafficLight green_light;
    green_light.tag = Green;
    green_light.Green_duration = 10;
    
    //@ assert light_duration(green_light) == 10;
}
