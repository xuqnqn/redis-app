/*************************************************************************
      > File Name: RedisConfig.h
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: 2019年09月09日 星期一 19时28分20秒
 ************************************************************************/

#ifndef _REDISCONFIG_H
#define _REDISCONFIG_H

#include <string>
 
class RedisConfig
{
public:
    RedisConfig();
    std::string getRedisIP();//获取ip
    int getRedisPort();//获取端口号
 
};
 
#endif
