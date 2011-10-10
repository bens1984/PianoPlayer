#ifndef __oscreceive_h_
#define __oscreceive_h_

#define OSC_RX_ACTIVE	//define for a build that receives OSC

#include "osc/OscReceivedElements.h"
#include "osc/OscPacketListener.h"
#include "ip/UdpSocket.h"

#include "pthread.h"

#include <list>
#include <vector>

using namespace std;

enum OSCCommands
{
	oscNothing,
	oscUpdate
};

struct OSCData
{
	OSCCommands header;
	vector<float> data;
	vector<int> idata;
};

class ExamplePacketListener : public osc::OscPacketListener {
protected:
	pthread_mutex_t* mymutex;
    virtual void ProcessMessage( const osc::ReceivedMessage& m, 
				const IpEndpointName& remoteEndpoint );
//public:
//	void SetMutex(pthread_mutex_t* mut);
};

extern pthread_mutex_t* oscmutex;
extern std::list<OSCData> rxCommands;

static void *startListenThread(void *arg);

class OSCReceive
{
private:
	pthread_t* listenThread;

public:
	OSCReceive();
	~OSCReceive();

	void StartReception();
	void StopReception();

	OSCData ReadAPacket();
};

#endif //__oscreceive_h_