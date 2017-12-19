//Kunal Mukherjee
//9/12/2017
//Mr.Randall
//CS475

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>


using namespace std;

int main(int argc, char* argv[])
{
    //check to see if the correct number of arguments are given    
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " port_number" << endl;
        exit(1);
    }

    //converting the char to int	
    int port = atoi(argv[1]);
    //putting "localhost" into a string
    string host = "localhost";

    //use DNS to get IP Address
    struct hostent *hostEntry;
    hostEntry = gethostbyname(host.c_str());

    //setup socket address structure
    struct sockaddr_in server_addr_in;
    //clears the address variable
    memset(&server_addr_in,0,sizeof(server_addr_in));
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_port = htons(port);    
    memcpy(&server_addr_in.sin_addr, hostEntry->h_addr_list[0], hostEntry->h_length);

    //create socket
    int SocketD = socket(PF_INET,SOCK_STREAM,0);
    //connect to server
    int connected = connect(SocketD,(struct sockaddr *)&server_addr_in,sizeof(server_addr_in));

    //buffer that will receive the message from the server
    char buffer[80];     
    //the string that will capture what the user enters
    string line;
    //askes to enter the user to enter a message
    cout << "Enter a message" << endl;

    while(1)
    {
	//gets the line that the user enters
        getline(cin,line);
        //attached an EOL to the end of the string, so that it terminates
	line.append("\n");
        //send the data to the server
        send(SocketD, line.c_str(), line.length(),0);
        //receive the buffer and receive the response
        recv( SocketD , buffer , 80 ,0 );
        //print the response from server
        cout << buffer;
    }
    //closes the socket
    close(SocketD);
    return 0;
}
