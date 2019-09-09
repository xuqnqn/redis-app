#ifndef __PROXY_TASK_H__
#define __PROXY_TASK_H__

#include <stdint.h>
#include "Task.h"

typedef void (*pdu_handler_t)(uint32_t conn_uuid);

class CProxyTask : public CTask
{
public:
    CProxyTask(uint32_t conn_uuid, pdu_handler_t pdu_handler);
	virtual ~CProxyTask();
	virtual void run();

private:
	uint32_t 		m_conn_uuid;
	pdu_handler_t	m_pdu_handler;
};

#endif

