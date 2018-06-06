// -------------------------------------------------------------------------
//    @FileName			:    NFCGameServerToDBModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-01-02
//    @Module           :    NFCGameServerToDBModule
//    @Desc             :
// -------------------------------------------------------------------------

#ifndef NFC_GAMESERVER_TO_DB_NETCLIENT_MODULE_H
#define NFC_GAMESERVER_TO_DB_NETCLIENT_MODULE_H

#include "NFComm/NFMessageDefine/NFMsgDefine.h"
#include "NFComm/NFPluginModule/NFINetModule.h"
#include "NFComm/NFPluginModule/NFINetClientModule.h"
#include "NFComm/NFPluginModule/NFIGameServerNet_ClientModule.h"
#include "NFComm/NFPluginModule/NFIGameServerNet_ServerModule.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFINetModule.h"
#include "NFComm/NFPluginModule/NFIClassModule.h"
#include "NFComm/NFPluginModule/NFIElementModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFPluginModule/NFIGameServerToDBModule.h"

class NFCGameServerToDBModule : public NFIGameServerToDBModule
{
public:
	NFCGameServerToDBModule(NFIPluginManager* p)
    {
        pPluginManager = p;
		mLastReportTime = 0;
    }
    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();
    virtual bool AfterInit();

    virtual void TransmitToDB(const int nHashKey, const int nMsgID, const google::protobuf::Message& xData);

protected:

    void OnSocketWSEvent(const NFSOCK nSockIndex, const NF_NET_EVENT eEvent, NFINet* pNet);

protected:
    void TransPBToProxy(const NFSOCK nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);

	NFINT64 mLastReportTime;

    NFILogModule* m_pLogModule;
    NFIKernelModule* m_pKernelModule;
    NFIClassModule* m_pClassModule;
    NFIElementModule* m_pElementModule;
	NFINetClientModule* m_pNetClientModule;
    NFIGameServerNet_ServerModule* m_pGameServerNet_ServerModule;
};

#endif