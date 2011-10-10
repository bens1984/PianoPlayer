#include "OSCReceive.h"
#include <iostream>

#define PORT 7124

namespace MusiVerse
{
	pthread_mutex_t* oscmutex;
	std::list<OSCData> rxCommands;
}

using namespace MusiVerse;

void *startListenThread(void *arg)
{
    ExamplePacketListener listener;
	//listener.SetMutex(oscmutex);
    UdpListeningReceiveSocket s(IpEndpointName( IpEndpointName::ANY_ADDRESS, PORT ),
            &listener );

    s.RunUntilSigInt();

	return NULL;
}

void ExamplePacketListener::ProcessMessage( const osc::ReceivedMessage& m, const IpEndpointName& remoteEndpoint )
{
    try{
        // example of parsing single messages. osc::OsckPacketListener
        // handles the bundle traversal.
        
		OSCData d;
		d.header = oscNothing;

		osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
		if( strcmp( m.AddressPattern(), "/obs") == 0 )	// this is a packet of feature data: /obs len x x x x
		{
            int len = (arg++)->AsInt32();
            for (int i = 0; i < len; i++)
                d.data.push_back((arg++)->AsFloat());	// the observed state
			d.header = oscUpdate;
        } 
		if (d.header != oscNothing)
		{
			pthread_mutex_lock(MusiVerse::oscmutex);	//wait for the lock
			MusiVerse::rxCommands.push_back(d);
			pthread_mutex_unlock(MusiVerse::oscmutex);
		}
    }catch( osc::Exception& e )
	{
        // any parsing errors such as unexpected argument types, or 
        // missing arguments get thrown as exceptions.
        std::cout << "error while parsing message: "
            << m.AddressPattern() << ": " << e.what() << "\n";
    }
}
//void ExamplePacketListener::SetMutex(pthread_mutex_t* mut)
//{
//	mymutex = mut;
//}

OSCReceive::OSCReceive()
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	MusiVerse::oscmutex = new pthread_mutex_t;
	pthread_mutex_init(MusiVerse::oscmutex, &attr);
	//is it locked to start?
	pthread_mutex_unlock(MusiVerse::oscmutex);
}
OSCReceive::~OSCReceive()
{
	delete MusiVerse::oscmutex;
	delete listenThread;
}

void OSCReceive::StartReception()
{
	int i = 0;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	listenThread = new pthread_t();
	pthread_create(listenThread, &attr, &startListenThread, (void *)i);
}
void OSCReceive::StopReception()
{
	pthread_cancel(*listenThread);
}
OSCData OSCReceive::ReadAPacket()
{
	OSCData o;
	o.header = oscNothing;
	if (pthread_mutex_trylock(MusiVerse::oscmutex) == 0)
	{
		if (MusiVerse::rxCommands.size() > 0)
		{
			o = MusiVerse::rxCommands.front();
			MusiVerse::rxCommands.pop_front();
		}
		pthread_mutex_unlock(MusiVerse::oscmutex);
	}
	return o;
}