#!/bin/bash
gcc server.c -o server -lfcgi
service nginx start
./server
/bin/bash