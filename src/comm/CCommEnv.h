

namespace comm
{
    const uint16    INST_ID_MIN    =    UINT16_MIN;
    const uint16    INST_ID_MAX    =    UINT16_MAX;
    const int       INST_MAX_COUNT =    (INST_ID_MAX - INST_ID_MIN) + 1;
    
    

    class CCommEnv
    {
        CCommInst*      m_vInsts[INST_MAX_COUNT];

    };
}