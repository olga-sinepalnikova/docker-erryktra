FROM nginx
WORKDIR /home/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./server.c .
COPY ./run.sh .
# RUN hwclock --hctosys
RUN apt-get update 
RUN apt-get install -y gcc apt-utils libfcgi-dev spawn-fcgi
ENTRYPOINT ["sh", "./run.sh"]