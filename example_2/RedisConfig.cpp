/*************************************************************************
      > File Name: RedisConfig.cpp
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: 2019年09月09日 星期一 19时29分26秒
 ************************************************************************/

#include "RedisConfig.h"
#include <sstream>
 
RedisConfig::RedisConfig()
{
 
}
 
std::string RedisConfig::getRedisIP()
{
    return "127.0.0.1";//设置为本机ip
}
 
int RedisConfig::getRedisPort()
{
    return 6379;
}
