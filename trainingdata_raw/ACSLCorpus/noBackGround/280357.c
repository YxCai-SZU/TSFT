#include <stdbool.h>
#include <stdint.h>

enum Achievement_Tag {
    Sprint,
    Marathon,
    Relay
};

struct Achievement {
    enum Achievement_Tag tag;
    union {
        struct {
            uint32_t points;
        } Sprint;
        struct {
            uint32_t hours;
        } Marathon;
        struct {
            uint8_t team_size;
        } Relay;
    };
};

/*@
    assigns \nothing;
*/
void test_achievement(void) {
    struct Achievement team_race;
    team_race.tag = Relay;
    team_race.Relay.team_size = 8;
    
    //@ assert ((team_race).tag == Sprint ? (team_race).Sprint.points :         (team_race).tag == Marathon ? (team_race).Marathon.hours :         (team_race).Relay.team_size) == 8;
}

/*@
    assigns \nothing;
*/
void test_no_participants(void) {
    struct Achievement sprint_race;
    sprint_race.tag = Sprint;
    sprint_race.Sprint.points = 10;
    
    //@ assert !((sprint_race).tag == Relay && (sprint_race).Relay.team_size == 0);
}

/*@
    assigns \nothing;
*/
int main(void) {
    return 0;
}
