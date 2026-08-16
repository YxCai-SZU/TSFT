#include <stdbool.h>
#include <stdint.h>

typedef enum {
    Theater,
    Cinema,
    GameRoom
} Tag;

typedef struct {
    char* name;
    uint16_t capacity;
} Theater_data;

typedef struct {
    char* name;
    uint8_t screens;
} Cinema_data;

typedef struct {
    char* name;
    uint32_t games;
} GameRoom_data;

typedef union {
    Theater_data Theater;
    Cinema_data Cinema;
    GameRoom_data GameRoom;
} Data;

typedef struct {
    Tag tag;
    Data data;
} Entertainment;

bool test_entertainment(Entertainment e) {
    bool result;
    //@ ghost Entertainment e_ghost = e;

    if (e.tag == Theater) {
        result = (e.data.Theater.capacity >= 1000);
        //@ assert ((e_ghost).tag == Theater);
        //@ assert ((e_ghost).tag == Theater ? (e_ghost).data.Theater.capacity : 0) >= 1000 ==> ((((e_ghost)).tag == Theater) && (((e_ghost)).tag == Theater ? ((e_ghost)).data.Theater.capacity : 0) >= 1000);
    } else {
        result = false;
    }

    return result;
}

/*@
    requires ((e).tag == Theater) && ((e).tag == Theater ? (e).data.Theater.capacity : 0) >= 1000;
    ensures ((((e)).tag == Theater) && (((e)).tag == Theater ? ((e)).data.Theater.capacity : 0) >= 1000);
*/
void no_small_stages(Entertainment e) {
    //@ assert ((e).tag == Theater);
    //@ assert ((e).tag == Theater ? (e).data.Theater.capacity : 0) >= 1000;
    //@ assert ((((e)).tag == Theater) && (((e)).tag == Theater ? ((e)).data.Theater.capacity : 0) >= 1000);
}

/*@
    requires ((e).tag == Cinema);
    ensures !((e).tag == GameRoom);
*/
void no_games_in_cinemas(Entertainment e) {
    //@ assert ((e).tag == Cinema);
    //@ assert !((e).tag == GameRoom);
}

/*@
    requires ((e).tag == Theater);
    ensures !((e).tag == Cinema);
*/
void no_screens_in_theaters(Entertainment e) {
    //@ assert ((e).tag == Theater);
    //@ assert !((e).tag == Cinema);
}

/*@
    requires ((e).tag == GameRoom);
    ensures !((e).tag == Theater) && !((e).tag == Cinema);
*/
void test_gamerroom(Entertainment e) {
    //@ assert ((e).tag == GameRoom);
    //@ assert !((e).tag == Theater);
    //@ assert !((e).tag == Cinema);
}

/*@
    requires ((e).tag == Theater) && ((e).tag == Theater ? (e).data.Theater.capacity : 0) >= 1000;
    ensures ((e).tag == Theater) && ((e).tag == Theater ? (e).data.Theater.capacity : 0) >= 1000;
*/
void test_entertainment_func(Entertainment e) {
    //@ assert ((e).tag == Theater);
    //@ assert ((e).tag == Theater ? (e).data.Theater.capacity : 0) >= 1000;
}

int main() {
    return 0;
}
