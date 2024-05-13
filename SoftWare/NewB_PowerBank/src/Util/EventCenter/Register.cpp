#include "./Register.h"
std::map<UINT64, std::vector<IEventReceive*>> CRegister::m_msgID2ReceivePtrs = std::map < UINT64, std::vector<IEventReceive*> > {};

CRegister::CRegister()
{
    m_msgID2ReceivePtrs.clear();
}


CRegister::~CRegister()
{
}

bool CRegister::RegisterByID(UINT64 u64MsgId, IEventReceive* pReceive)
{
    if (m_msgID2ReceivePtrs.find(u64MsgId) != m_msgID2ReceivePtrs.end())
    {
        for (auto item = m_msgID2ReceivePtrs[u64MsgId].begin(); item != m_msgID2ReceivePtrs[u64MsgId].end(); item++)
        {
            if (*item == pReceive)
            {
                return false;
            }
        }
        m_msgID2ReceivePtrs[u64MsgId].push_back(pReceive);
    }
    else
    {
        m_msgID2ReceivePtrs[u64MsgId] = std::vector < IEventReceive* > {pReceive};
    }
    return true;
}

bool CRegister::UnRegisterByID(UINT64 u64MsgId, IEventReceive* pReceive)
{
    if (m_msgID2ReceivePtrs.find(u64MsgId) != m_msgID2ReceivePtrs.end())
    {
        auto vt = m_msgID2ReceivePtrs.find(u64MsgId);
        auto vv = vt->second;
        for (auto item = vv.begin(); item != vv.end(); item++)
        {
            if (*item == pReceive)
            {
                vv.erase(item);
                break;
            }
        }
        return true;
    }
    return false;
}

bool CRegister::SendNotify(UINT64 u64MsgId, UINT64 u64Event)
{
    if (m_msgID2ReceivePtrs.find(u64MsgId) == m_msgID2ReceivePtrs.end())
    {
        return false;
    }
    for (auto item = m_msgID2ReceivePtrs[u64MsgId].begin(); item != m_msgID2ReceivePtrs[u64MsgId].end(); item++)
    {
        if (*item != nullptr)
        {
            (*item)->EventRecevie(u64MsgId, u64Event);
        }
    }
    return true;
}