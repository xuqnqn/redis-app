cmake_minimum_required(VERSION 2.8)

#工程主要参考TeamTalk
#https://github.com/meili/TeamTalk/tree/master/server/src/db_proxy_server

PROJECT(mysqlredis_pool)

AUX_SOURCE_DIRECTORY(. SRC_LIST)

#mysql客户端,我们不使用c++版本，因为它依赖boost库，太啰嗦
#mysql-connector-c++-1.1.8-linux-el7-x86-64bit.tar.gz -- https://downloads.mysql.com/archives/c-cpp/
#推荐使用c版本 -- https://downloads.mysql.com/archives/c-c/
#mysql-community-devel-5.7.18-1.el7.x86_64.rpm 自带了c语言客户端头文件和库
#安装说明 -- http://blog.csdn.net/libaineu2004/article/details/76212125
SET(MYSQL_INCLUDE_DIR /usr/include/mysql)
SET(MYSQL_LIB /usr/lib64/mysql)

#redis客户端,使用c版本 -- https://github.com/redis/hiredis
#安装说明 -- http://blog.csdn.net/libaineu2004/article/details/76209267
SET(REDIS_INCLUDE_DIR /usr/local/include/hiredis/)
SET(REDIS_LIB /usr/local/lib/)

INCLUDE_DIRECTORIES(${MYSQL_INCLUDE_DIR} ${REDIS_INCLUDE_DIR})
LINK_DIRECTORIES(${MYSQL_LIB} ${REDIS_LIB})

#ADD_EXECUTABLE必须在TARGET_LINK_LIBRARIES前面，否则会报错
ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_LIST})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} mysqlclient hiredis pthread)
