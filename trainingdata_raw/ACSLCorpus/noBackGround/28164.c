#include <stdbool.h>
#include <stdint.h>

enum Tool { Saw, Drill, Hammer };

struct Tool_Saw { uint16_t length; };
struct Tool_Drill { uint32_t speed; };
struct Tool_Hammer { uint8_t weight; };

union Tool_Data {
    struct Tool_Saw saw;
    struct Tool_Drill drill;
    struct Tool_Hammer hammer;
};

struct Tool_Union {
    enum Tool tag;
    union Tool_Data data;
};

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    return a * b;
}

/*@
    requires tool.tag == Hammer;
    ensures \result == (tool.tag == Hammer && tool.data.hammer.weight > 5);
    assigns \nothing;
*/
bool check_tool(struct Tool_Union tool)
{
    //@ assert tool.tag == Hammer;
    return tool.tag == Hammer && tool.data.hammer.weight > 5;
}
