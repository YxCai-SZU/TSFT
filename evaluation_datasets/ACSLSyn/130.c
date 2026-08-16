#include <stdint.h>
#include <stdbool.h>

/* ACSL predicates from first snippet */
/*@
    predicate is_heavy_duty(integer tag, integer length, integer speed, integer weight) =
        (tag == 2 && weight > 10) || (tag == 0 && length > 20);

    predicate is_precision(integer tag, integer length, integer speed, integer weight) =
        tag == 1 && speed > 1000;

    logic integer total_speed(integer speed) = speed + 0;

    lemma precision_not_heavy: \forall integer tag, length, speed, weight;
        is_precision(tag, length, speed, weight) ==> !is_heavy_duty(tag, length, speed, weight);
*/

enum ToolTag { SAW, DRILL, HAMMER };

struct Tool {
    enum ToolTag tag;
    union {
        uint16_t length;
        uint32_t speed;
        uint16_t weight;
    } data;
};

/* ACSL predicates from second snippet */
/*@
    predicate valid_range(integer s, integer t) =
        s >= 1 && t >= 1 && s <= 100000 && t <= 100000;

    predicate valid_vector(integer len, int *v) =
        len >= 1 && len <= 100000 &&
        \forall integer i; 0 <= i < len ==> v[i] >= 1 && v[i] <= 100000;

    predicate in_range(integer i, integer s, integer t) =
        (s <= i && i <= t) || (t <= i && i <= s);

    lemma vector_properties_preserved:
        \forall integer len, int *v, integer idx;
        valid_vector(len, v) && 0 <= idx < len ==>
            v[idx] >= 1 && v[idx] <= 100000;
*/

struct Tool recommend_tool(uint32_t m) {
    struct Tool t;
    t.tag = DRILL;
    t.data.speed = 1200;
    return t;
}

int func(int s, int t, int *v, int len) {
    int count = 0;
    int index = 0;
    
    while (index < len) {
        int i = v[index];
        
        if ((s <= i && i <= t) || (t <= i && i <= s)) {
            count += 1;
        }
        index += 1;
    }
    return count;
}

struct ToolWithCount {
    struct Tool tool;
    int count;
};

struct ToolWithCount analyze_and_recommend(uint32_t m, int s, int t, int *v, int len) {
    struct ToolWithCount result;
    
    result.tool = recommend_tool(m);
    result.count = func(s, t, v, len);
    
    return result;
}

int main() {
    struct ToolWithCount result;
    uint32_t m = 800;
    int v[] = {5, 100, 200, 50, 75};
    int len = 5;
    int s = 10;
    int t = 100;
    
    result = analyze_and_recommend(m, s, t, v, len);
    
    return 0;
}
