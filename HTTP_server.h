#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H
int CreateHTTPserver();
void sendGETresponse(int fdSocket, char* method, char* data);
void sendPUTresponse(int fdSocket, char* method, char* data, char* filename);
#endif 
