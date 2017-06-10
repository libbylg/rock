#ifndef __CCommSrvMgr_H_
#define __CCommSrvMgr_H_

namespace comm
{
    
    class CCommSrvMgr
    {
    public:
        //  注册服务
        int         reg(CCommAddr addr, uint16 serverId, const char* desc);
        
        //  注销服务实例
        void        unreg(CCommAddr addr);
        
        //  获取服务实例地址
        int         get(uint16 serverId, CCommAddr& addr);
    };
    
}

#endif//__CCommSrvMgr_H_

