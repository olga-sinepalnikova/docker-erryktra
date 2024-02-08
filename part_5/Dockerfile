FROM nginx
WORKDIR /home/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./server.c .
COPY ./run.sh /home/run.sh
RUN apt-get update -y && apt-get upgrade -y && apt-get install -y gcc libfcgi-dev spawn-fcgi && rm -rf /var/lib/apt/lists
RUN touch /var/run/nginx.pid; \
    chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /var/cache/nginx; \
    chown -R nginx:nginx /home; \
    touch /var/run/nginx.pid; \
    chown -R nginx:nginx /var/run/nginx.pid;
RUN chmod 755 /usr/bin/wall; \
 chmod 777 /home/run.sh; \
 chmod 755 /usr/bin/chsh; \
 chmod 755 /usr/bin/expiry; \
 chmod 755 /usr/bin/gpasswd; \
 chmod 755 /usr/bin/passwd; \
 chmod 755 /usr/bin/chage; \
 chmod 755 /bin/umount; \
 chmod 755 /usr/bin/newgrp; \
 chmod 755 /usr/bin/chfn; \
 chmod 755 /bin/mount; \
 chmod 755 /bin/su; \
 chmod 755 /sbin/unix_chkpwd; \
 chown -R nginx:nginx /var/run/nginx.pid
USER nginx
ENTRYPOINT ["sh", "./run.sh"]