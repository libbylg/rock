#ifndef __TCommMessage_H_
#define __TCommMessage_H_

//ATTR_VERSION        =   0,      //  uint8           //  消息版本（只可读取不可设置）
//ATTR_BYTEORDER      =   1,      //  uint8           //  字节序（只可读取不可设置）
//ATTR_DIRECTION      =   2,      //  uint8           //  方向（请求还是应答）
//ATTR_SRC_ADDR       =   10,     //  {uint64,uint16} //  源地址
//ATTR_DST_ADDR       =   11,     //  {uint64,uint16} //  目的地址
//ATTR_SRC_SRVID      =   12,     //  uint16          //  发送端的服务ID
//ATTR_DST_SRVID      =   13,     //  uint16          //  接收端的服务ID
//ATTR_COMPRES        =   14,     //  uint8           //  是否经过了压缩
//ATTR_SESSION_ID     =   15,     //  uint64          //  会话ID

struct TCommMessage
{
    uint8   version;    //  消息版本号
    uint8   noused;     //  保留字段，当前版本填写0
    uint8   flag[2];    //  标记
    uint32  len;        //  数据长度
    uint8   data[0];    //  数据区域
};

//[xxxx-xxxx]
//  编解码方便
//
struct  TCommAttr
{
    uint8   type;
    uint8   id;
};

struct  TCommAttrVar
{
    uint8   type;
    uint16  len;
};



#endif//__TCommMessage_H_



