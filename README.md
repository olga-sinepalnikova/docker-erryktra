## Part 1. Готовый докер

* Взять официальный докер образ с **nginx** и выкачать его при помощи `docker pull`
    * Заранее нужно установить docker через `sudo snap install docker`
    * Затем через `sudo docker pull nginx` берём официальный докер образ
    * ![выкачка официального образа nginx](images/01/docker_pull_nginx.png)
* Проверить наличие докер образа через `docker images`
    * Проверяем наличие образа через `sudo docker images`
    * ![Проверка наличия образа](images/01/cheking_for_nginx_image.png)
* Запустить докер образ через `docker run -d [image_id|repository]`
    * Запуск докера через `sudo docker run -d c20060033e06`
    * ![запуск докера](images/01/running_docker.png)
* Проверить, что образ запустился через `docker ps`
    * Проверка, что образ запустился
    * ![проверка работы образа](images/01/docker_ps.png)
* Посмотреть информацию о контейнере через `docker inspect [container_id|container_name]`
    * Просмотр информации (вставлена только часть вывода)
    * ![Информация о контейнере](images/01/docker_inspect.png)
* По выводу команды определить и поместить в отчёт размер контейнера, список замапленных портов и ip контейнера (Сам вывод очень большой, поэтому оставлены только необходимые части)
    * размер контейнера
        * 186779301
        * ![размер контейнера](images/01/docker_size.png)
    * список замапленных портов
        * 80/tcp
        * ![список замапленных портов](images/01/docker_exposed_ports.png)
    * ip контейнера
        * 172.17.0.2
        * ![ip контейнера](images/01/docker_image_id.png)
* Остановить докер образ через `docker stop [container_id|container_name]`
    * Останавливаем докер образ командой `sudo docker stop 1aa25f21a6bf`
    * ![остановка докер образа](images/01/docker_stop.png)
* Проверить, что образ остановился через `docker ps`
    * Проверяем остановился ли образ
    * ![проверка, что образ остановился](images/01/docker_stop_check.png)
* Запустить докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду *run*
    * Используем команду `sudo docker run -p 127.0.0.1:443:443 -p 127.0.0.1:80:80 -d c20060033e06`
    * ![запуск докера на портах 80 и 443](images/01/docker_ports_80_and_443.png)
* Проверить, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**
    * переходим по адресу
    * ![стартовая страница nginx](images/01/localhost_page.png)
* Перезапустить докер контейнер через `docker restart [container_id|container_name]`
    * перезапустим контейнер командой `sudo docker restart a0493887ea46` (вторая команда на скрине)
    * ![перезапущенный докер](images/01/restarted_docker.png)
* Проверить любым способом, что контейнер запустился
    * на скрине видно, что сначала в STATUS указано 19 секунд работы и CREATED равен 20 секундам. После перезапуска время создания всё также отсылает к 45 секундам назад, а время работы всего 6 секунд.
    * ![перезапущенный докер](images/01/restarted_docker.png)

## Part 2. Операции с контейнером
* Прочитать конфигурационный файл *nginx.conf* внутри докер контейнера через команду *exec*
    * Используем команду `docker exec charming_clarke cat etc/nginx/nginx.conf`
    * ![Прочтение файла](images/02/reading_nginx_conf.png)
* Создать на локальной машине файл *nginx.conf*
* Настроить в нем по пути */status* отдачу страницы статуса сервера **nginx**
    * см [файл nginx.conf](part_2/nginx.conf)
    * скрин файла
    * ![скриншот nginx.conf](images/02/nginx_conf_screenshot.png)
* Скопировать созданный файл *nginx.conf* внутрь докер образа через команду `docker cp`
    * Использована команда: `docker cp part_2/nginx.conf charming_clarke:etc/nginx/nginx.conf`
    * ![копирование nginx.conf в контейнер](images/02/copy_nginx_conf_to_container.png)
* Перезапустить **nginx** внутри докер образа через команду *exec*
    * `docker exec my_nginx nginx -s reload` 
    * ![перезапуск nginx в контейнере](images/02/nginx_restart.png)
* Проверить, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**
    * ![Страница status на localhost](images/02/localhost_status_page.png)
* Экспортировать контейнер в файл *container.tar* через команду *export*
    * Использована команда: `docker export my_nginx > container.tar`
    * ![экспорт контейнера](images/02/export_container.png)
* Остановить контейнер
    * используем `docker stop my_nginx`
    * ![остановка контейнера](images/02/stop_container.png)
*  Удалить образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры
    * используем `docker rmi -f c20060033e06` (-f = force)
    * ![удалить образ](images/02/delete_image.png)
* Удалить остановленный контейнер
    * используем `docker rm my_nginx`
    * ![Удалить контейнер](images/02/delete_container.png)
* Импортировать контейнер обратно через команду *import*
    * используем `docker import -c 'cmd ["nginx", "-g", "daemon off;"]' -c 'ENTRYPOINT ["/docker-entrypoint.sh"]' container.tar nginx`
    * ![импорт котейнера](images/02/import_container.png)
* Запустить импортированный контейнер
    * docker run -p 80:80 -p 443:80 -d --name imported a6bd71f48f68
    * ![запуск импортированного контейнера](images/02/run_imported_container.png)
* Проверить, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**
    * заходим по адресу *localhost:80/status*
    * ![странциа localhost/status](images/02/working_page.png)