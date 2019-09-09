#include "DBPool.h"
#include "CachePool.h"
#include "ThreadPool.h"
#include "ProxyTask.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h> //daemonize
#include <string>
#include <string.h>

void handler(uint32_t conn_uuid)
{
    printf("hello,%d\n", conn_uuid);

    CDBManager* pDBManger = CDBManager::getInstance();
    if (!pDBManger) {
        printf("DBManager init failed");
        return;
    }

    CDBConn* pDBConn = pDBManger->GetDBConn("teamtalk_master");//get a db conn
    if (pDBConn) {
        string strSql = "select * from IMUser";
        CResultSet* pResultSet = pDBConn->ExecuteQuery(strSql.c_str());
        if (pResultSet)
        {
            delete pResultSet;
        }

        pDBManger->RelDBConn(pDBConn);//注意，con用完之后一定要记得归还,ReleaseConnection
    }
}

int main(int argc, char* argv[])
{
    signal(SIGPIPE, SIG_IGN);
/*
    //案例1,仅仅使用mysql连接池，不使用线程池
    CDBManager* pDBManger = CDBManager::getInstance();
    if (!pDBManger) {
        printf("DBManager init failed");
        return -1;
    }

    CDBConn* pDBConn = pDBManger->GetDBConn("teamtalk_master");//get a db conn
    if (pDBConn) {
        string strSql = "select * from IMUser";
        CResultSet* pResultSet = pDBConn->ExecuteQuery(strSql.c_str());
        if (pResultSet)
        {
            string strResult, strSalt;
            uint32_t nId, nGender, nDeptId, nStatus;
            string strNick, strAvatar, strEmail, strRealName, strTel, strDomain,strSignInfo;
            while (pResultSet->Next()) {
                nId = pResultSet->GetInt("id");
                strResult = pResultSet->GetString("password");
                strSalt = pResultSet->GetString("salt");
                strNick = pResultSet->GetString("nick");
                nGender = pResultSet->GetInt("sex");
                strRealName = pResultSet->GetString("name");
                strDomain = pResultSet->GetString("domain");
                strTel = pResultSet->GetString("phone");
                strEmail = pResultSet->GetString("email");
                strAvatar = pResultSet->GetString("avatar");
                nDeptId = pResultSet->GetInt("departId");
                nStatus = pResultSet->GetInt("status");
                strSignInfo = pResultSet->GetString("sign_info");
            }

            delete pResultSet;
        }

        pDBManger->RelDBConn(pDBConn);//注意，con用完之后一定要记得归还,ReleaseConnection
    }

    //案例2,使用mysql连接池，也使用线程池
    //top -H -p <pid> 终端查看某个特定进程<pid>并检查该进程内运行的线程状况
    CThreadPool thread_pool;
    thread_pool.Init(10);

    CTask* pTask1 = new CProxyTask(1, handler);//void CWorkerThread::Execute()执行完任务会删除指针CTask*
    thread_pool.AddTask(pTask1);
    CTask* pTask2 = new CProxyTask(2, handler);
    thread_pool.AddTask(pTask2);
    CTask* pTask3 = new CProxyTask(3, handler);
    thread_pool.AddTask(pTask3);
*/
    //案例3,仅仅使用redis连接池，不使用线程池
    CacheManager* pCacheManager = CacheManager::getInstance();
    if (!pCacheManager) {
        printf("CacheManager init failed");
        return -1;
    }

    CacheConn* pCacheConn = pCacheManager->GetCacheConn("redis");
    if (pCacheConn)
    {
        string strVal = "sodesiname";
        pCacheConn->set("total_user_update", strVal);
        string str = pCacheConn->get("total_user_update");
        printf("%s\n", str.c_str());
        pCacheManager->RelCacheConn(pCacheConn);
    }

    //进程挂起，等待任务执行完成
    printf("\ninput:\n");
    char s[20];
    gets(s);  //等待输入字符串直到回车结束

    return 0;
}
