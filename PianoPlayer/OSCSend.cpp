/* 
    Simple example of sending an OSC message using oscpack.
*/


#include "OSCSend.h"

OSCSend::OSCSend(const char * addr, int prt)
{
	ip = IpEndpointName(addr,prt); // ADDRESS, PORT );
	transmitSocket = new UdpTransmitSocket( ip );
}

// send a vector of floats. 
int OSCSend::oscSend(const char* message, int size, float* data)
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
void OSCSend::oscSend(const char* header, int size, const double* data)
{
    if (size > 0)
    {
        unsigned int bufSize = OUTPUT_BUFFER_SIZE; //sizeof(header) + size*sizeof(float) + 128;   // it needs more than 64 bytes of padding for OSC stuff... not sure the exact number
//        bufSize = (bufSize < OUTPUT_BUFFER_SIZE ? bufSize : OUTPUT_BUFFER_SIZE);
        char buffer[bufSize];
        if (size > 980)
            size = 980;
//        for (int j = 0; j < size; j += bufSize/sizeof(float))  // this should split really large packets, but won't mark the header!
//        {
            osc::OutboundPacketStream p( buffer, bufSize );
            
            p << osc::BeginBundleImmediate << osc::BeginMessage( header );
            for (int i=0; i < size; i++)	{
                p << (float)data[i];
            }
            
            p << osc::EndMessage << osc::EndBundle;
            
            transmitSocket->Send( p.Data(), p.Size() );
        }
//    }
}
void OSCSend::oscSend(const char* header, int size, const int* data)
{
	int i;
	char buffer[OUTPUT_BUFFER_SIZE];
	osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
	
	p << osc::BeginBundleImmediate << osc::BeginMessage( header );
	for (i=0; i< size; i++)	{
		p << data[i];
	}
	
	p << osc::EndMessage << osc::EndBundle;
	
	transmitSocket->Send( p.Data(), p.Size() );
}
void OSCSend::oscSend(const char* header, const char* message)
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
void OSCSend::oscSend(const char* header, int argc, float argv[], const char* message)
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

static OSCSend* myOSC = 0x00;
OSCSend* OSCSend::getSingleton()
{
	if (myOSC == 0x00)
		myOSC = new OSCSend(OSC_DESTINATION, OSC_PORT);
	return myOSC;
}
