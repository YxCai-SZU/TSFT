// Generated C + ACSL

#include <string.h>

typedef struct {
    char* meta_http_x_forwarded_for;
    char* meta_remote_addr;
    int has_forwarded_for;
} Request;

/*@
    requires request != 0;
    requires \valid_read(request);
    requires request->has_forwarded_for ==> 
             request->meta_http_x_forwarded_for != \null;
    requires request->has_forwarded_for ==> 
             \valid_read(request->meta_http_x_forwarded_for);
    requires !request->has_forwarded_for ==> 
             request->meta_remote_addr != \null;
    requires !request->has_forwarded_for ==> 
             \valid_read(request->meta_remote_addr);
    assigns \nothing;
    ensures \result != \null;
    ensures \valid_read(\result);
*/
char* GetUserIP(Request* request)
{
  char* ip;
  if (request->has_forwarded_for)
  {
    ip = request->meta_http_x_forwarded_for;
    /*@ assert ip != \null; */
    /*@ assert \valid_read(ip); */
  }
  else
  {
    ip = request->meta_remote_addr;
    /*@ assert ip != \null; */
    /*@ assert \valid_read(ip); */
  }
  return ip;
}