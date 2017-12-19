#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int port = 60100;

int main()
{
    int SocketD;
    SocketD = socket(AF_INET, SOCK_STREAM,0);
    cout << "My Socket Discription: " << SocketD << endl;

    struct sockaddr_in self;
    self.sin_family = AF_INET;
    self.sin_port = htons(port);
    self.sin_addr.s_addr = INADDR_ANY;

    bind(SocketD, (struct sockaddr*)&self, sizeof(self));

    cout << "Server is listening on port: " << port << endl;
    listen(SocketD, 20);
    struct sockaddr_in client_addr;

    int addrlen = sizeof(client_addr);

    int clientfd = accept(SocketD, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen);

    cout << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << endl;

    while(1)
    {
        bool endofline = false;
        int receive = 0;
        int iter = 0;
        char rebuffer[80];
        char buffer[80];

        while(!endofline)
        {
            receive = recv(clientfd, rebuffer, 80, 0);
            for (int i = 0; i <receive; i++, iter++)
            {
                if(rebuffer[i] == '\n')
                {
                    endofline = true;
                }
                buffer[iter] = rebuffer[i];

                if (endofline)
                {
                    buffer[iter+1] = 0;
                }
            }

        }
         send(clientfd,buffer,iter+1,0);

    }

    close(clientfd);
    close(SocketD);
    return 0;

}
