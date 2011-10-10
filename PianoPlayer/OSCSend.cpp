/* 
    Simple example of sending an OSC message using oscpack.
*/


#include "OSCSend.h"

myOSCHandle::myOSCHandle(const char * addr, int prt)
{
	ip = IpEndpointName(addr,prt); // ADDRESS, PORT );
	transmitSocket = new UdpTransmitSocket( ip );
}

// send a vector of floats. 
int myOSCHandle::oscSend(char* message, int size, float* data)
//int oscSend(char* message, int argc, double argv[])
{	    
	int i;
	char buffer[OUTPUT_BUFFER_SIZE];
	osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
	
	p << osc::BeginBundleImmediate
	<< osc::BeginMessage( message );
	for (i=0; i< size; i++)
	{
		p << data[i];
	}
	
	p << osc::EndMessage << osc::EndBundle;
	
	transmitSocket->Send( p.Data(), p.Size() );
	
	return i;
}

void myOSCHandle::oscSend(const char* header, const char* message)
{	    
	char buffer[OUTPUT_BUFFER_SIZE];
	osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
	
	p << osc::BeginBundleImmediate
	<< osc::BeginMessage( header )
	<< message
	<< osc::EndMessage 
	<< osc::EndBundle;
	
	transmitSocket->Send( p.Data(), p.Size() );
}
void myOSCHandle::oscSend(const char* header, int argc, float argv[], const char* message)
{	    
	char buffer[OUTPUT_BUFFER_SIZE];
	osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
	
	p << osc::BeginBundleImmediate
	<< osc::BeginMessage( header );
	for (int i=0; i< argc; i++)
	{
		p << argv[i];
	}
	p << message
	<< osc::EndMessage 
	<< osc::EndBundle;
	
	transmitSocket->Send( p.Data(), p.Size() );
}

static myOSCHandle* myOSC = 0x00;
myOSCHandle* myOSCHandle::getSingleton()
{
	if (myOSC == 0x00)
		myOSC = new myOSCHandle(OSC_DESTINATION, OSC_PORT);
	return myOSC;
}
