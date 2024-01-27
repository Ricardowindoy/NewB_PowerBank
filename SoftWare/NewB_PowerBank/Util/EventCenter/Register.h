#ifndef CREG_H
#define CREG_H

#ifndef UINT64
#define UINT64 unsigned long long
#endif

#include "IEventReceive.h"
#include <map>
#include <vector>

class CRegister
{
public:
    CRegister();
    ~CRegister();
    static bool RegisterByID(UINT64 u64MsgId, IEventReceive* pReceive);
    static bool UnRegisterByID(UINT64 u64MsgId, IEventReceive* pReceive);
    static bool SendNotify(UINT64 u64MsgId, UINT64 u64Event);

    static std::map<UINT64, std::vector<IEventReceive*>> m_msgID2ReceivePtrs;
};

#endif