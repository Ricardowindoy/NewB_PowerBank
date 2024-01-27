#ifndef IEREC_H
#define IEREC_H
#ifndef UINT64
#define UINT64 unsigned long long
#endif
class IEventReceive
{
public:
    IEventReceive(){};
    ~IEventReceive(){};
    virtual void EventRecevie(UINT64 u64MsgId, UINT64 u64Event)=0;
};
#endif