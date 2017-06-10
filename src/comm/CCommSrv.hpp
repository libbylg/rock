#ifndef __CCommSrvMgr_H_
#define __CCommSrvMgr_H_

namespace comm
{
    
    class CCommSrvMgr
    {
    public:
        int         reg(CCommAddr addr, uint16 serverId, const char* desc);
        
        void        unreg(CCommAddr addr);
        
        int         get(uint16 serverId, CCommAddr& addr);
        
        void        list(uint16 serverId, CVectorT<CCommAddr>& addrs);
    };
    
}