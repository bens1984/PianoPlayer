#ifndef __SimpleSend_h_
#define __SimpleSend_h_

#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"

#define OUTPUT_BUFFER_SIZE 1024
#define OSC_DESTINATION "127.0.0.1"
#define OSC_PORT 7130

class myOSCHandle
{
protected:
	IpEndpointName ip;
	UdpTransmitSocket* transmitSocket;
	//osc::OutboundPacketStream p;
public:
	myOSCHandle(const char * addr, int prt);

	// send a vector of floats. 
	int oscSend(char* message, int size, float* data);

	void oscSend(const char* header, const char* message);
	void oscSend(const char* header, int argc, float argv[], const char* message);
	
	static myOSCHandle* getSingleton();

	/*int oscSend(char* message, int argc, std::string argv[])
	//int oscSend(char* message, int argc, double argv[])
	{	    
		char buffer[OUTPUT_BUFFER_SIZE];
		osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
	    
		int i;
		p << osc::BeginBundleImmediate
			<< osc::BeginMessage( message );
		for (i=0; i< argc; i++)
		{
			p << argv[i].c_str();
		}

		p << osc::EndMessage << osc::EndBundle;
	    
		transmitSocket->Send( p.Data(), p.Size() );

		return i;
	}*/
};

//extern myOSCHandle* myOSC;		//global OSC handle
#endif //__SimpleSend_h_