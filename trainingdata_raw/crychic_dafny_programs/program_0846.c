// Generated C + ACSL

#include <stddef.h>

#define API_DOMAIN 1

typedef struct {
    int userID;
} Response;

/*@
    assigns \nothing;
    ensures \result.userID >= 0;
    ensures \result.userID <= 2147483647;
*/
Response JsonResponse(const char* userId, void* map);

/*@
    requires key != 0;
    requires domain != 0;
    requires path != 0;
    assigns \nothing;
    ensures \result.userID >= 0;
    ensures \result.userID <= 2147483647;
*/
Response api(int key, int domain, const char* path)
{
  Response response = JsonResponse("dummyUserId", NULL);
  /*@ assert response.userID >= 0; */
  /*@ assert response.userID <= 2147483647; */
  return response;
}

/*@
    requires key != 0;
    assigns \nothing;
    ensures (long)\result >= 0;
    ensures (long)\result <= 2147483647;
*/
char* getUserId(int key)
{
  Response response = api(key, API_DOMAIN, "/user");
  int userId = response.userID;
  /*@ assert userId >= 0; */
  /*@ assert userId <= 2147483647; */
  /*@ assert (long)((char*)(long)userId) == (long)userId; */
  return (char*)(long)userId;
}