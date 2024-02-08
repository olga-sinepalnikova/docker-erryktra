скачиваем docker-compose и buildx

запускаем docker-compose build
![build](images/docker_compose_build.png)

как закончит запускаем docker-compose up
![up](images/docker_compose_up_result.png)
(нет команды, так как были запущены через docker-compose build && docker-compose up)

переходим на localhost:80

![localhost](images/localhost_hello_world.png)

видим GET-запрос в командной строке. это значит, что был переход на адрес localhost:80

![get](images/get_request_from_laptop.png)