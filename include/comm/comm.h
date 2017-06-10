#ifndef __comm_H_
#define __comm_H_

#include "share/type.h"


enum CommConst
{
    ATTR_VERSION        =   0,      //  uint8           //  消息版本（只可读取不可设置）
    ATTR_BYTEORDER      =   1,      //  uint8           //  字节序（只可读取不可设置）
    ATTR_DIRECTION      =   2,      //  uint8           //  方向（请求还是应答）
    ATTR_SRC_ADDR       =   10,     //  {uint64,uint16} //  源地址
    ATTR_DST_ADDR       =   11,     //  {uint64,uint16} //  目的地址
    ATTR_SRC_SRVID      =   12,     //  uint16          //  发送端的服务ID
    ATTR_DST_SRVID      =   13,     //  uint16          //  接收端的服务ID
    ATTR_COMPRES        =   14,     //  uint8           //  是否经过了压缩
    ATTR_SESSION_ID     =   15,     //  uint64          //  会话ID
    
    SERVER_ID_MIN       =   0,
    SERVER_ID_MAX       =   1000,
    SERVER_MAX_COUNT    =   (SERVER_ID_MAX - SERVER_ID_MIN) + 1,
    
    SERVER_COMMMGR      =   0,
    SERVER_SRVMGR       =   1,
    
    INVALID_INSTID      =   0xFFFF,
};

struct  CommAddr
{
    uint64  ip;
    uint16  instId;
};

/// 消息处理句柄
typedef void (*CommMessageHandle)(void* atttr, uint16 len, void* data);


/// 初始化和销毁通信客户端
extern "C"  int     comm_init(uint16* instId, CommMessageHandle* messageHandle);
extern "C"  void    comm_exit(uint16  instId);


/// 向指定的通信实例发送消息(点对点)
extern "C"  int     comm_send_inst(uint16 selfId, CommAddr  dst, uint32  len, void* data);
extern "C"  int     comm_recv_inst(uint16 selfId, CommAddr* dst, uint32* len, void* data);


/// 将通信实例注册为一个服务
extern "C"  int     comm_reg  (uint16 selfId, uint16 srvId, const char* desc);
extern "C"  void    comm_unreg(uint16 selfId, uint16 srvId);


/// 向指定的服务发送消息(点对服务集群)
extern "C"  int     comm_send_srv(uint16 srvId, uint32 len, void* data);


#endif//__comm_H_



