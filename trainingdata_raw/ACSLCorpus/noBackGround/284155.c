#include <stdbool.h>

enum PersonTag { Scientist, Engineer, Artist };

struct Person {
    enum PersonTag tag;
    union {
        struct {
            char* field;
            unsigned int papers_published;
        } scientist;
        struct {
            char* specialty;
            unsigned int projects_completed;
        } engineer;
        struct {
            char* medium;
            unsigned int works_exhibited;
        } artist;
    };
};

/*@
    requires p.tag == Scientist;
    ensures \result == true;
    assigns \nothing;
*/
bool verify_person_func(struct Person p) {
    //@ assert p.tag == Scientist;
    //@ assert p.scientist.papers_published >= 0;
    return true;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
