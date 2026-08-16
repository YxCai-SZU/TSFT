// Generated C + ACSL

typedef struct {
    int statusCode;
    char* body;
} Response_t;

typedef struct {
    int isRunning;
} App_t;

/*@
    assigns \result.statusCode, \result.body;
    ensures \result.statusCode == statusCode;
    ensures \result.body == body;
*/
Response_t Response(int statusCode, char* body) {
    Response_t resp;
    resp.statusCode = statusCode;
    resp.body = body;
    return resp;
}

Response_t HomeRoute(void);
void Run(App_t* app);
void Shutdown(App_t* app);

/*@
    assigns \nothing;
*/
void Main(void)
{
  App_t app;
  app.isRunning = 0;
  Response_t response = HomeRoute();
  /*@ assert (response.statusCode == 200); */
  Run(&app);
  /*@ assert app.isRunning; */
}

/*@
    assigns \nothing;
    ensures \result.statusCode == 200;
*/
Response_t HomeRoute(void)
{
  char* responseBody = "Hello, world!";
  Response_t response = Response(200, responseBody);
  /*@ assert response.statusCode == 200; */
  return response;
}

/*@
    requires !app->isRunning;
    assigns app->isRunning;
    ensures app->isRunning;
*/
void Run(App_t* app)
{
  app->isRunning = 1;
}

/*@
    requires app->isRunning == 1;
    assigns app->isRunning;
    ensures app->isRunning == 0;
*/
void Shutdown(App_t* app)
{
  app->isRunning = 0;
}