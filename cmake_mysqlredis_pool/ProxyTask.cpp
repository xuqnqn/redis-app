
#include "ProxyTask.h"

CProxyTask::CProxyTask(uint32_t conn_uuid, pdu_handler_t pdu_handler)
{
    m_conn_uuid = conn_uuid;
    m_pdu_handler = pdu_handler;
}

CProxyTask::~CProxyTask()
{

}

void CProxyTask::run()
{
    if (m_pdu_handler) {
        m_pdu_handler(m_conn_uuid);
    }
}
