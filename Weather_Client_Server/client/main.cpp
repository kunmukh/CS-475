//Kunal Mukherjee
//9/12/2017
//Mr.Randall
//CS475
//client

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
    char buffer[100000];

    //the string that will capture what the user enters
    string choice;
    //askes to enter the user to enter a message
    cout << "\nWhich City's weather do you want to see?\n1>\tEvansville IN\n2>\tPeoria IL\n3>\tHouston TX\n4>\tPut a Star(*) and put the zip code that you want to inquire about (e.g *47714)\n5>\tQuit" << endl;
    //gets the line that the user enters
    getline(cin,choice);
    //attached an EOL to the end of the string, so that it terminates
    choice.append("\n");

    int receive;
    int con = 1;

    while(choice[0] != '5')
    {
        if (con == 0)
        {

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

            //if (connected)
                //cout << "Reconnected" << endl;
        }

        //send the data to the server
        //cout << "Sending" << endl;
        send(SocketD, choice.c_str(), choice.length(),0);
        //receive the buffer and receive the response
        memset (buffer,0,100000);
        receive = recv( SocketD , buffer , 100000 ,0 );
        //cout << "Receiving" << endl;

        while (receive != 0)
        {
            //Putting a new line in place of '$'
            for (int i = 0; i < 100000; i++)
            {
                if (buffer[i] == '$')
                    buffer[i] = '\n';
            }
            cout << buffer << endl;
            memset (buffer,0,100000);
            receive = recv( SocketD , buffer , 100000 ,0 );
        }

        //closes the socket
        close(SocketD);
        con = 0;
        //Clearing the choice and the buffer associated with it
        choice.clear();
        cin.clear();

        cout << "\nWhich City's weather do you want to see?\n1>\tEvansville IN\n2>\tPeoria IL\n3>\tHouston TX\n4>\tPut a Star(*) and put the zip code that you want to inquire about (e.g *47714)\n5>\tQuit" << endl;
        //gets the line that the user enters
        getline(cin,choice);
        //attached an EOL to the end of the string, so that it terminates
        choice.append("\n");
    }

    return 0;
}
