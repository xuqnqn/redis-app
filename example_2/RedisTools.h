/*************************************************************************
      > File Name: RedisTools.h
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: 2019年09月09日 星期一 19时29分53秒
 ************************************************************************/

#ifndef _REDISTOOLS_H
#define _REDISTOOLS_H

#include <iostream>
#include <vector>
#include <hiredis/hiredis.h>
#include "RedisConfig.h"
 
using namespace std;
 
class RedisTool
{
public:
    RedisTool();
    ~RedisTool();
    int setString(string key, string value);
    string getString(string key);
 
    int setList(string key,vector<int> value);
    vector<int> getList(string key);
 
private:
    void init();
    redisContext *m_redis;
    RedisConfig m_config;
};
 
#endif
