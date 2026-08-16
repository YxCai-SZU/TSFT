// Generated C + ACSL

typedef struct {
  int isSuperuser;
} User;

typedef struct {
  User user;
} Request;

typedef enum {
  AdminRoute = 0,
  PollRoute = 1
} RouteType;

/*@
    requires \valid(request);
    assigns \nothing;
    ensures (request->user.isSuperuser) ==> (\result == AdminRoute);
    ensures (!(request->user.isSuperuser)) ==> (\result == PollRoute);
*/
int GetRoute(Request* request)
{
  int route;
  User user = request->user;
  if (user.isSuperuser)
  {
    route = AdminRoute;
    /*@ assert route == 0; */
  }
  else
  {
    route = PollRoute;
  }
  return route;  // Dafny implicit return
}

/*@
    requires route == 0 || route == 1;
    assigns \nothing;
    ensures route == 0 ==> \result != \null;
    ensures route == 1 ==> \result != \null;
*/
char* RouteToPath(int route)
{
  char* path;
  if ((route == AdminRoute))
  {
    path = "/admin";
    /*@ assert \valid_read(path); */
  }
  else
  {
    path = "/poll/1";
  }
  return path;  // Dafny implicit return
}