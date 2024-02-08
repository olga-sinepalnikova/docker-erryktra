#include <stdio.h>

// #include "fcgi_stdio.h"
#include <fcgiapp.h>

int main(void){
    FCGX_Init();
    int sockfd = FCGX_OpenSocket("127.0.0.1:8080", 100);
    FCGX_Request req;
    FCGX_InitRequest(&req, sockfd, 0);

    while (FCGX_Accept_r(&req) >= 0) {
        FCGX_FPrintF(req.out, "Content-Type: text/html\n\n");
        FCGX_FPrintF(req.out, "hello world");
        FCGX_Finish_r(&req);
    }
    return 0;
}