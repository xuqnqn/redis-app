/*************************************************************************
      > File Name: main.cpp
      > Author: Xu Qingqing
      > Mail: xuqnqn@qq.com
      > Created Time: 2019年09月09日 星期一 19时30分54秒
 ************************************************************************/

/*
 * Author:wamgbaojia
 * 2018.10.10
 * email:wangbaojia_hrbeu@163.com
 *
 * */
#include <iostream>
#include <vector>
#include "RedisTools.h"
 
using namespace std;
 
 
int main()
{
    RedisTool redis;
    //测试 string
    redis.setString("wangbaojia","test1");
    string result = redis.getString("wangbaojia");
    cout<<"result="<<result<<endl;
    //测试list
    vector<int> vec ={1,2,3,4};
    redis.setList("bao",vec);
    vector<int> vecResult = redis.getList("bao");
    for(int i=0;i<vecResult.size();i++)
    {
        cout<<vecResult[i]<<" ";
    }
    cout << endl;
 
    return 0;
}
