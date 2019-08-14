//Kunal Mukherjee
//CS475
//Project 2 - Server
//10/2/17

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <iostream>
#include "Markup.h"
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int port = 60100;
int wunder = 80;

//int mykey = 7f3257e4026c9381;

int main()
{
  cout << "\t\tThe Weather Application" << endl;
  //Creating a Socket
  int SocketD;
  SocketD = socket(AF_INET, SOCK_STREAM,0);
  cout << "My Socket Discription: " << SocketD << endl;

  //Populating the Socket
  struct sockaddr_in self;
  self.sin_family = AF_INET;
  self.sin_port = htons(port);
  self.sin_addr.s_addr = INADDR_ANY;

  //Binding the socket
  bind(SocketD, (struct sockaddr*)&self, sizeof(self));

  cout << "Server is listening on port: " << port << endl;
  listen(SocketD, 20);

  //*******************************************************************************************************//

  //Opening file to write the xml data
  ofstream outfile ("xml_data.xml");
  ofstream outfile3 ("parsed_data.dat");
  ifstream infile ("parsed_data.dat");

    //The variables needed for a sucessful connection
  char buffer[100000];
  char rebuffer[80];
  int receive;
  string data;
  string information;
  string error = "Error in Loading the XML file. Wait for a few seconds and try again. If the issue continue to persist come back tomorrow";

  //*********************************************************************************************************//

  //Connection to the Client
  struct sockaddr_in client_addr;
  int addrlen = sizeof(client_addr);
  int clientfd = accept(SocketD, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen);

  cout << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << endl;
  recv( clientfd, rebuffer , 80 ,0 );

  while(1)
        {
          while (rebuffer[0] == '1' || rebuffer[0] == '2' || rebuffer[0] == '3' || rebuffer[0] == '*')
                {

                  //Evansville
                  if (rebuffer[0] == '1')
                            {
                              //Opening the File stream
                              ofstream outfile ("xml_data.xml");
                              ofstream outfile3 ("parsed_data.dat");
                              ifstream infile ("parsed_data.dat");

                              //int wunder = 80;
                              //putting "localhost" into a string
                              string host = "api.wunderground.com"; //api.wunderground.com

                              //use DNS to get IP Address
                              struct hostent *hostEntry;
                              hostEntry = gethostbyname(host.c_str());

                              //setup socket address structure
                              struct sockaddr_in server_addr_in;
                              //clears the address variable
                              memset(&server_addr_in,0,sizeof(server_addr_in));
                              server_addr_in.sin_family = AF_INET;
                              server_addr_in.sin_port = htons(wunder);
                              memcpy(&server_addr_in.sin_addr, hostEntry->h_addr_list[0], hostEntry->h_length);

                              //create socket
                              int Weather = socket(PF_INET,SOCK_STREAM,0);
                              //connect to server
                              int connected = connect(Weather,(struct sockaddr *)&server_addr_in,sizeof(server_addr_in));
                              cout << "Connected to wunderground Server." << endl;

                              //Getting the XML document from the server
                              cout << "Evansville's Weather Called" << endl;
                              send(Weather, "GET /api/7f3257e4026c9381/forecast10day/geolookup/conditions/q/47714.xml HTTP/1.0\r\nHost: api.wunderground.com\r\n\r\n",
                               strlen("GET /api/7f3257e4026c9381/forecast10day/geolookup/conditions/q/47714.xml HTTP/1.0\r\nHost: api.wunderground.com\r\n\r\n"), 0);

                              //Receiving the data from the server
                              receive = recv( Weather, buffer , 100000 ,0 );
                              //Loop to take out the useless buffer infront of the xml
                              for (int i = 0; i < 100000; i++)
                                {
                                  if (buffer[i] == '<')
                                    break;

                                  buffer[i] = ' ';
                                }
                              //Loop to keep reading from the buffer and writing it into a file until the connection is terminated from the other side
                              while (receive != 0)
                                {
                                  outfile << buffer;
                                  memset (buffer,0 ,100000);
                                  receive = recv( Weather, buffer , 100000 ,0 );

                                }
                            //Closing the weather connection
                            close(Weather);

                            CMarkup xml;
                            bool bSucess = xml.Load( "xml_data.xml" );
                            //a checker to see if the whole XML file has been downloaded or not.
                            if (bSucess)
                                cout << "Correct Load" << endl;

                            if (!bSucess)
                                cout << "InCorrect Load" << endl;

                           if (bSucess)
                            {
                                  xml.FindElem(); // root ORDER element
                                  xml.IntoElem(); // inside ORDER

                                  outfile3 << "\n\nThe Current Weather Observations are as follows" << endl;
                                  //Parsing the XML document and writing the parsed data to a file
                                  while ( xml.FindElem("current_observation") )
                                    {
                                      xml.IntoElem();

                                      xml.FindElem( "temperature_string" );
                                      data = xml.GetData();
                                      outfile3 << "Temperature: " <<  data << endl;

                                      xml.FindElem( "relative_humidity" );
                                      data = xml.GetData();
                                      outfile3 << "Relative Humidity: " << data << endl;

                                      xml.FindElem( "feelslike_string" );
                                      data = xml.GetData();
                                      outfile3 << "Feels like: " << data << endl;

                                      xml.FindElem( "visibility_mi" );
                                      data = xml.GetData();
                                      outfile3 << "Visibility in miles: " << data << endl;

                                      xml.FindElem( "precip_today_string" );
                                      data = xml.GetData();
                                      outfile3 << "Precipitation Today: " << data << endl;

                                      xml.FindElem( "pressure_in" );
                                      data = xml.GetData();
                                      outfile3 << "Pressure: " << data << endl;

                                      xml.OutOfElem();
                                    }

                                  xml.ResetPos();
                                  xml.FindElem(); // root ORDER element
                                  xml.IntoElem(); // inside ORDER

                                  outfile3 << "\nThe five Day Forecast are as follows: " << endl;
                                  while ( xml.FindElem("forecast") )
                                    {
                                      xml.IntoElem();
                                      xml.FindElem("simpleforecast");
                                      xml.IntoElem();
                                      xml.FindElem("forecastdays");
                                      xml.IntoElem();
                                      xml.FindElem("forecastday");

                                      //Second Day
                                      outfile3 << "\nThe Second Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Third Day
                                      outfile3 << "\nThe Third Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Fourth Day
                                      outfile3 << "\nThe Fourth Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Fifth Day
                                      outfile3 << "\nThe Fifth Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      xml.OutOfElem();
                                      outfile3 << "\n";
                                    }

                                  //closes the outfile
                                  outfile3.close();
                                //Getting each line from a file and putting a token after the end of the line that is used in the client and sending it to the client
                                while (getline (infile,information))
                                {
                                    information.append("$");
                                    send(clientfd,information.c_str(),information.size(),0);
                                }

                            }

                         //If the XML was iccorectly downloaded an error is send out
                        if (!bSucess)
                            send(clientfd,error.c_str(),error.size(),0);

                         //The files are closed and the client connection is terminated
                        outfile.close();
                        outfile3.close();
                        infile.close();

                        close(clientfd);
                        rebuffer[0] = '$';
                    }

                 //Peoria
                 //Evansville
                  if (rebuffer[0] == '2')
                            {
                              //Opening the File stream
                              ofstream outfile ("xml_data.xml");
                              ofstream outfile3 ("parsed_data.dat");
                              ifstream infile ("parsed_data.dat");

                              //int wunder = 80;
                              //putting "localhost" into a string
                              string host = "api.wunderground.com"; //api.wunderground.com

                              //use DNS to get IP Address
                              struct hostent *hostEntry;
                              hostEntry = gethostbyname(host.c_str());

                              //setup socket address structure
                              struct sockaddr_in server_addr_in;
                              //clears the address variable
                              memset(&server_addr_in,0,sizeof(server_addr_in));
                              server_addr_in.sin_family = AF_INET;
                              server_addr_in.sin_port = htons(wunder);
                              memcpy(&server_addr_in.sin_addr, hostEntry->h_addr_list[0], hostEntry->h_length);

                              //create socket
                              int Weather = socket(PF_INET,SOCK_STREAM,0);
                              //connect to server
                              int connected = connect(Weather,(struct sockaddr *)&server_addr_in,sizeof(server_addr_in));
                              cout << "Connected to wunderground Server." << endl;

                              //Getting the XML document from the server
                              cout << "Peoria's Weather Called" << endl;
                              send(Weather, "GET /api/7f3257e4026c9381/forecast10day/geolookup/conditions/q/61615.xml HTTP/1.0\r\nHost: api.wunderground.com\r\n\r\n",
                               strlen("GET /api/7f3257e4026c9381/forecast10day/geolookup/conditions/q/61615.xml HTTP/1.0\r\nHost: api.wunderground.com\r\n\r\n"), 0);

                              //Receiving the data from the server
                              receive = recv( Weather, buffer , 100000 ,0 );
                              //Loop to take out the useless buffer infront of the xml
                              for (int i = 0; i < 100000; i++)
                                {
                                  if (buffer[i] == '<')
                                    break;

                                  buffer[i] = ' ';
                                }
                              //Loop to keep reading from the buffer and writing it into a file until the connection is terminated from the other side
                              while (receive != 0)
                                {
                                  outfile << buffer;
                                  memset (buffer,0 ,100000);
                                  receive = recv( Weather, buffer , 100000 ,0 );

                                }
                            //Closing the weather connection
                            close(Weather);

                            CMarkup xml;
                            bool bSucess = xml.Load( "xml_data.xml" );
                            //a checker to see if the whole XML file has been downloaded or not.
                            if (bSucess)
                                cout << "Correct Load" << endl;

                            if (!bSucess)
                                cout << "InCorrect Load" << endl;

                           if (bSucess)
                            {
                                  xml.FindElem(); // root ORDER element
                                  xml.IntoElem(); // inside ORDER

                                  outfile3 << "\n\nThe Current Weather Observations are as follows" << endl;
                                  //Parsing the XML document and writing the parsed data to a file
                                  while ( xml.FindElem("current_observation") )
                                    {
                                      xml.IntoElem();

                                      xml.FindElem( "temperature_string" );
                                      data = xml.GetData();
                                      outfile3 << "Temperature: " <<  data << endl;

                                      xml.FindElem( "relative_humidity" );
                                      data = xml.GetData();
                                      outfile3 << "Relative Humidity: " << data << endl;

                                      xml.FindElem( "feelslike_string" );
                                      data = xml.GetData();
                                      outfile3 << "Feels like: " << data << endl;

                                      xml.FindElem( "visibility_mi" );
                                      data = xml.GetData();
                                      outfile3 << "Visibility in miles: " << data << endl;

                                      xml.FindElem( "precip_today_string" );
                                      data = xml.GetData();
                                      outfile3 << "Precipitation Today: " << data << endl;

                                      xml.FindElem( "pressure_in" );
                                      data = xml.GetData();
                                      outfile3 << "Pressure: " << data << endl;

                                      xml.OutOfElem();
                                    }

                                  xml.ResetPos();
                                  xml.FindElem(); // root ORDER element
                                  xml.IntoElem(); // inside ORDER

                                  outfile3 << "\nThe five Day Forecast are as follows: " << endl;
                                  while ( xml.FindElem("forecast") )
                                    {
                                      xml.IntoElem();
                                      xml.FindElem("simpleforecast");
                                      xml.IntoElem();
                                      xml.FindElem("forecastdays");
                                      xml.IntoElem();
                                      xml.FindElem("forecastday");

                                      //Second Day
                                      outfile3 << "\nThe Second Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Third Day
                                      outfile3 << "\nThe Third Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Fourth Day
                                      outfile3 << "\nThe Fourth Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Fifth Day
                                      outfile3 << "\nThe Fifth Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      xml.OutOfElem();
                                      outfile3 << "\n";
                                    }

                                  //closes the outfile
                                  outfile3.close();
                                //Getting each line from a file and putting a token after the end of the line that is used in the client and sending it to the client
                                while (getline (infile,information))
                                {
                                    information.append("$");
                                    send(clientfd,information.c_str(),information.size(),0);
                                }

                            }

                         //If the XML was iccorectly downloaded an error is send out
                        if (!bSucess)
                            send(clientfd,error.c_str(),error.size(),0);

                         //The files are closed and the client connection is terminated
                        outfile.close();
                        outfile3.close();
                        infile.close();

                        close(clientfd);
                        rebuffer[0] = '$';
                    }

                //Houston
                  if (rebuffer[0] == '3')
                            {
                              //Opening the File stream
                              ofstream outfile ("xml_data.xml");
                              ofstream outfile3 ("parsed_data.dat");
                              ifstream infile ("parsed_data.dat");

                              //int wunder = 80;
                              //putting "localhost" into a string
                              string host = "api.wunderground.com"; //api.wunderground.com

                              //use DNS to get IP Address
                              struct hostent *hostEntry;
                              hostEntry = gethostbyname(host.c_str());

                              //setup socket address structure
                              struct sockaddr_in server_addr_in;
                              //clears the address variable
                              memset(&server_addr_in,0,sizeof(server_addr_in));
                              server_addr_in.sin_family = AF_INET;
                              server_addr_in.sin_port = htons(wunder);
                              memcpy(&server_addr_in.sin_addr, hostEntry->h_addr_list[0], hostEntry->h_length);

                              //create socket
                              int Weather = socket(PF_INET,SOCK_STREAM,0);
                              //connect to server
                              int connected = connect(Weather,(struct sockaddr *)&server_addr_in,sizeof(server_addr_in));
                              cout << "Connected to wunderground Server." << endl;

                              //Getting the XML document from the server
                              cout << "Houston's Weather Called" << endl;
                              send(Weather, "GET /api/7f3257e4026c9381/forecast10day/geolookup/conditions/q/77058.xml HTTP/1.0\r\nHost: api.wunderground.com\r\n\r\n",
                               strlen("GET /api/7f3257e4026c9381/forecast10day/geolookup/conditions/q/77058.xml HTTP/1.0\r\nHost: api.wunderground.com\r\n\r\n"), 0);

                              //Receiving the data from the server
                              receive = recv( Weather, buffer , 100000 ,0 );
                              //Loop to take out the useless buffer infront of the xml
                              for (int i = 0; i < 100000; i++)
                                {
                                  if (buffer[i] == '<')
                                    break;

                                  buffer[i] = ' ';
                                }
                              //Loop to keep reading from the buffer and writing it into a file until the connection is terminated from the other side
                              while (receive != 0)
                                {
                                  outfile << buffer;
                                  memset (buffer,0 ,100000);
                                  receive = recv( Weather, buffer , 100000 ,0 );

                                }
                            //Closing the weather connection
                            close(Weather);

                            CMarkup xml;
                            bool bSucess = xml.Load( "xml_data.xml" );
                            //a checker to see if the whole XML file has been downloaded or not.
                            if (bSucess)
                                cout << "Correct Load" << endl;

                            if (!bSucess)
                                cout << "InCorrect Load" << endl;

                           if (bSucess)
                            {
                                  xml.FindElem(); // root ORDER element
                                  xml.IntoElem(); // inside ORDER

                                  outfile3 << "\n\nThe Current Weather Observations are as follows" << endl;
                                  //Parsing the XML document and writing the parsed data to a file
                                  while ( xml.FindElem("current_observation") )
                                    {
                                      xml.IntoElem();

                                      xml.FindElem( "temperature_string" );
                                      data = xml.GetData();
                                      outfile3 << "Temperature: " <<  data << endl;

                                      xml.FindElem( "relative_humidity" );
                                      data = xml.GetData();
                                      outfile3 << "Relative Humidity: " << data << endl;

                                      xml.FindElem( "feelslike_string" );
                                      data = xml.GetData();
                                      outfile3 << "Feels like: " << data << endl;

                                      xml.FindElem( "visibility_mi" );
                                      data = xml.GetData();
                                      outfile3 << "Visibility in miles: " << data << endl;

                                      xml.FindElem( "precip_today_string" );
                                      data = xml.GetData();
                                      outfile3 << "Precipitation Today: " << data << endl;

                                      xml.FindElem( "pressure_in" );
                                      data = xml.GetData();
                                      outfile3 << "Pressure: " << data << endl;

                                      xml.OutOfElem();
                                    }

                                  xml.ResetPos();
                                  xml.FindElem(); // root ORDER element
                                  xml.IntoElem(); // inside ORDER

                                  outfile3 << "\nThe five Day Forecast are as follows: " << endl;
                                  while ( xml.FindElem("forecast") )
                                    {
                                      xml.IntoElem();
                                      xml.FindElem("simpleforecast");
                                      xml.IntoElem();
                                      xml.FindElem("forecastdays");
                                      xml.IntoElem();
                                      xml.FindElem("forecastday");

                                      //Second Day
                                      outfile3 << "\nThe Second Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Third Day
                                      outfile3 << "\nThe Third Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Fourth Day
                                      outfile3 << "\nThe Fourth Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Fifth Day
                                      outfile3 << "\nThe Fifth Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      xml.OutOfElem();
                                      outfile3 << "\n";
                                    }

                                  //closes the outfile
                                  outfile3.close();
                                //Getting each line from a file and putting a token after the end of the line that is used in the client and sending it to the client
                                while (getline (infile,information))
                                {
                                    information.append("$");
                                    send(clientfd,information.c_str(),information.size(),0);
                                }

                            }

                         //If the XML was iccorectly downloaded an error is send out
                        if (!bSucess)
                            send(clientfd,error.c_str(),error.size(),0);

                         //The files are closed and the client connection is terminated
                        outfile.close();
                        outfile3.close();
                        infile.close();

                        close(clientfd);
                        rebuffer[0] = '$';
                    }

                        //Any zip
                  if (rebuffer[0] == '*')
                            {
                              cout << "Zip called: " << endl;
                              //Opening the File stream
                              ofstream outfile ("xml_data.xml");
                              ofstream outfile3 ("parsed_data.dat");
                              ifstream infile ("parsed_data.dat");

                              //int wunder = 80;
                              //putting "localhost" into a string
                              string host = "api.wunderground.com"; //api.wunderground.com
                              string request1 = "GET /api/7f3257e4026c9381/forecast10day/geolookup/conditions/q/";
                              string request2 = ".xml HTTP/1.0\r\nHost: api.wunderground.com\r\n\r\n";
                              char zip[5];
                              char temp1[10];
                              int temp;
                              for (int i = 0; i < 5; i++)
                              {
                                //cout << "rebuff" << rebuffer[i+1] << endl;
                                temp = rebuffer[i+1];
                                //cout << "temp" << temp << endl;
                                zip[i] = '0' + (temp - 48);
                                //cout << "zip" << zip[i] << endl;
                              }
                              string zipcode(zip, 5);
                              string request = request1 + zipcode + request2;
                              //cout << request << endl;
                              //cout << "GET /api/7f3257e4026c9381/forecast10day/geolookup/conditions/q/77058.xml HTTP/1.0\r\nHost: api.wunderground.com\r\n\r\n" << endl;

                              //use DNS to get IP Address
                              struct hostent *hostEntry;
                              hostEntry = gethostbyname(host.c_str());

                              //setup socket address structure
                              struct sockaddr_in server_addr_in;
                              //clears the address variable
                              memset(&server_addr_in,0,sizeof(server_addr_in));
                              server_addr_in.sin_family = AF_INET;
                              server_addr_in.sin_port = htons(wunder);
                              memcpy(&server_addr_in.sin_addr, hostEntry->h_addr_list[0], hostEntry->h_length);

                              //create socket
                              int Weather = socket(PF_INET,SOCK_STREAM,0);
                              //connect to server
                              int connected = connect(Weather,(struct sockaddr *)&server_addr_in,sizeof(server_addr_in));
                              cout << "Connected to wunderground Server." << endl;

                              //Getting the XML document from the server
                              cout << "A Custom Zip Called" << endl;
                              send(Weather, request.c_str(), request.length(), 0);

                              //Receiving the data from the server
                              receive = recv( Weather, buffer , 100000 ,0 );
                              //Loop to take out the useless buffer infront of the xml
                              for (int i = 0; i < 100000; i++)
                                {
                                  if (buffer[i] == '<')
                                    break;

                                  buffer[i] = ' ';
                                }
                              //Loop to keep reading from the buffer and writing it into a file until the connection is terminated from the other side
                              while (receive != 0)
                                {
                                  outfile << buffer;
                                  memset (buffer,0 ,100000);
                                  receive = recv( Weather, buffer , 100000 ,0 );

                                }
                            //Closing the weather connection
                            close(Weather);

                            CMarkup xml;
                            bool bSucess = xml.Load( "xml_data.xml" );
                            //a checker to see if the whole XML file has been downloaded or not.
                            if (bSucess)
                                cout << "Correct Load" << endl;

                            if (!bSucess)
                                cout << "InCorrect Load" << endl;

                           if (bSucess)
                            {
                                  xml.FindElem(); // root ORDER element
                                  xml.IntoElem(); // inside ORDER


                                  //Parsing the XML document and writing the parsed data to a file
                                  while ( xml.FindElem("location") )
                                    {
                                      xml.IntoElem();

                                      xml.FindElem( "country_name" );
                                      data = xml.GetData();
                                      outfile3 << "\n\nLocation (country, state, city):" << data;

                                      xml.FindElem( "state" );
                                      data = xml.GetData();
                                      outfile3 << ", " << data;

                                      xml.FindElem( "city" );
                                      data = xml.GetData();
                                      outfile3 << ", " <<  data << endl;

                                      xml.FindElem( "lat" );
                                      data = xml.GetData();
                                      outfile3 << "Latitude: " << data << endl;

                                      xml.FindElem( "lon" );
                                      data = xml.GetData();
                                      outfile3 << "Longitude: " << data << endl;

                                      xml.OutOfElem();
                                    }

                                  xml.ResetPos();
                                  xml.FindElem(); // root ORDER element
                                  xml.IntoElem();
                                outfile3 << "\n\nThe Current Weather Observations are as follows" << endl;
                                  while ( xml.FindElem("current_observation") )
                                    {
                                      xml.IntoElem();

                                      xml.FindElem( "temperature_string" );
                                      data = xml.GetData();
                                      outfile3 << "Temperature: " <<  data << endl;

                                      xml.FindElem( "relative_humidity" );
                                      data = xml.GetData();
                                      outfile3 << "Relative Humidity: " << data << endl;

                                      xml.FindElem( "feelslike_string" );
                                      data = xml.GetData();
                                      outfile3 << "Feels like: " << data << endl;

                                      xml.FindElem( "visibility_mi" );
                                      data = xml.GetData();
                                      outfile3 << "Visibility in miles: " << data << endl;

                                      xml.FindElem( "precip_today_string" );
                                      data = xml.GetData();
                                      outfile3 << "Precipitation Today: " << data << endl;

                                      xml.FindElem( "pressure_in" );
                                      data = xml.GetData();
                                      outfile3 << "Pressure: " << data << endl;

                                      xml.OutOfElem();
                                    }

                                  xml.ResetPos();
                                  xml.FindElem(); // root ORDER element
                                  xml.IntoElem(); // inside ORDER

                                  outfile3 << "\nThe five Day Forecast are as follows: " << endl;
                                  while ( xml.FindElem("forecast") )
                                    {
                                      xml.IntoElem();
                                      xml.FindElem("simpleforecast");
                                      xml.IntoElem();
                                      xml.FindElem("forecastdays");
                                      xml.IntoElem();
                                      xml.FindElem("forecastday");

                                      //Second Day
                                      outfile3 << "\nThe Second Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Third Day
                                      outfile3 << "\nThe Third Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Fourth Day
                                      outfile3 << "\nThe Fourth Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      //Fifth Day
                                      outfile3 << "\nThe Fifth Day Forecast: " << endl;
                                      xml.FindElem("forecastday");
                                      xml.IntoElem();
                                      xml.FindElem("date");
                                      xml.IntoElem();
                                      xml.FindElem( "pretty" );
                                      data  = xml.GetData();
                                      outfile3 << "Date: " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("high");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (High): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("low");
                                      xml.IntoElem();
                                      xml.FindElem( "fahrenheit" );
                                      data  = xml.GetData();
                                      outfile3 << "Temperature in Fahrenheit (Low): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "conditions" );
                                      data  = xml.GetData();
                                      outfile3 << "The Condition of the day: " << data << endl;
                                      xml.FindElem("qpf_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Precipitation all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("snow_allday");
                                      xml.IntoElem();
                                      xml.FindElem( "in" );
                                      data  = xml.GetData();
                                      outfile3 << "Snow all Day(in): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem("maxwind");
                                      xml.IntoElem();
                                      xml.FindElem( "mph" );
                                      data  = xml.GetData();
                                      outfile3 << "Max wind in (mph): " << data << endl;
                                      xml.OutOfElem();
                                      xml.FindElem( "avehumidity" );
                                      data  = xml.GetData();
                                      outfile3 << "Average humidity of the day: " << data << endl;
                                      xml.OutOfElem();

                                      xml.OutOfElem();
                                      outfile3 << "\n";
                                    }

                                  //closes the outfile
                                  outfile3.close();
                                //Getting each line from a file and putting a token after the end of the line that is used in the client and sending it to the client
                                while (getline (infile,information))
                                {
                                    information.append("$");
                                    send(clientfd,information.c_str(),information.size(),0);
                                }

                            }

                         //If the XML was iccorectly downloaded an error is send out
                        if (!bSucess)
                            send(clientfd,error.c_str(),error.size(),0);

                         //The files are closed and the client connection is terminated
                        outfile.close();
                        outfile3.close();
                        infile.close();

                        close(clientfd);
                        rebuffer[0] = '$';
                    }

                }

            //Waiitng for the next response
            cout << "Waiting for next request" << endl;
            //Accepting the next connection from a client machine
            struct sockaddr_in client_addr;
            addrlen = sizeof(client_addr);
            clientfd = accept(SocketD, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen);

            cout << "Connected To " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << endl;
            //clearing both the buffer so that no remainant data is sent
            memset (rebuffer,0,80);
            memset (buffer,0,100000);
            recv( clientfd, rebuffer , 80 ,0 );
            //cout << rebuffer[0] << endl;
        }


    //Closing the Socket
    close(SocketD);
    close(clientfd);

  return 0;

}
