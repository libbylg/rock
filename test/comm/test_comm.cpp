#define TEST(testid,desc) void test_##testid(const char* pDesc = desc)
#define RUN_TEST(testid) test##testid(null)
#define EXPECT_EQUAL(msg,expect,actual)     assert((expect) == (actual))
#define EXPECT_TRUE(msg,exp)                assert((exp))

TEST(T001, "测试正常消息收发")
{
    uint16 instid1 = INVALID_INSTID;
    int initRet1 = comm_init(&instid1, nullptr);
    EXPECT_EQUAL("初始化成功，应该返回0", 0, initRet1);
    EXPECT_TRUE("初始化成功，instId不应该为无效值", instid1 != INVALID_INSTID);
    
    uint16 instid2 = INVALID_INSTID;
    int initRet2 = comm_init(&instid1, nullptr);
    EXPECT_EQUAL("初始化成功，应该返回0", 0, instid2);
    EXPECT_TRUE("初始化成功，instId不应该为无效值", instid2 != INVALID_INSTID);
    
    char data[] = "Hello";
    uint32 sendLen = sizeof(data);
    int sendRet1 = comm_send_inst(instid1, instid2, 0, nullptr, sendLen, data);
    EXPECT_EQUAL("发送成功，应该返回0", 0, sendRet1);
    
    uint16 recvLen = 0;
    char   buffer[100] = {0};
    int recvRet1 = comm_recv_inst(instid2, null, &recvLen, buffer);
    EXPECT_EQUAL("收消息成功，应该返回0", 0, recvRet1);
    EXPECT_EQUAL("检查数据长度", sendLen, recvLen);
    EXPECT_TRUE("检查数据长度", 0 == memcmp(data, buffer, sendLen))
}


int main(int argc, char* argv[])
{
    RUN_TEST(T001);
    
    return 0;
}