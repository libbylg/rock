#include "comm/comm.h"

/// 初始化和销毁通信客户端
int     comm_init(uint16* instId, CommMessageHandle* messageHandle)
{
    return 0;
}

void    comm_exit(uint16  instId)
{
    return;
}


/// 向指定的通信实例发送消息(点对点)
int     comm_send_inst(uint16 instId, uint64  address, CommMessageOptons* attr, uint32  len, void* data)
{
    return 0;
}

int     comm_recv_inst(uint16 instId, uint64* address, CommMessageOptons* attr, uint32* len, void* data)
{

}

/// 将通信实例注册为一个服务
int     comm_reg(uint16 instId, uint16 serverId, const char* desc)
{

}

void    comm_unreg(uint16 instId, uint16 serverId)
{

}




/// 向指定的服务发送消息(点对服务集群)
int     comm_send_svrc(uint16 serverId, void* attr, uint32 len, void* data);
