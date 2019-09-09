//redistest.cpp
#include <stdio.h>
#include <hiredis/hiredis.h>
 
int main()
{
  redisContext* conn = redisConnect("127.0.0.1",6379);
  if(conn->err){
		printf("connection error:%s\n",conn->errstr);
  }
 
  redisReply* reply = (redisReply*)redisCommand(conn,"set foo 1234");
  freeReplyObject(reply);
 
  reply = (redisReply*)redisCommand(conn,"get foo");
  printf("%s\n",reply->str);
  freeReplyObject(reply);
 
  redisFree(conn);
  return 0;
}
