Собираем докер
``` bash
sudo docker build -t my_docker:1.0
# Можно задать любое имя и тег
```
![docker build](images/build_docker.png)

Проверяем что собралось верно, прописав `sudo docker run -d -p 80:81 my_new_docker`

![новый образ](images/new_image.png)

Проверяем localhost

![localhost/status](images/localhost_status.png)