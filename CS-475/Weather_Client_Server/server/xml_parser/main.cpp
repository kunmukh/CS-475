#include <iostream>
#include <fstream>
#include "Markup.h"
#include <string.h>

using namespace std;

int main()
{
    string data;
    ofstream outfile ("Parsed_Result.dat");
    ifstream infile2 ("Parsed_Result.dat");

    CMarkup xml;
    bool bSucess = xml.Load( "test1.xml" );

    if (bSucess)
      cout << "Correct Load" << endl;

    if (!bSucess)
      cout << "Correct Load" << endl;

    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER

    outfile << "The Current Weather Observations are as follows" << endl;
    while ( xml.FindElem("current_observation") )
      {
	xml.IntoElem();
	
	xml.FindElem( "temperature_string" );
	data = xml.GetData();
	outfile << "Temperature: " <<  data << endl;

	xml.FindElem( "relative_humidity" );
	data = xml.GetData();
	outfile << "Relative Humidity: " << data << endl;

	xml.FindElem( "feelslike_string" );
	data = xml.GetData();
	outfile << "Feels like: " << data << endl;

	xml.FindElem( "visibility_mi" );
	data = xml.GetData();
	outfile << "Visibility in miles: " << data << endl;

	xml.FindElem( "precip_today_string" );
	data = xml.GetData();
	outfile << "Precipitation Today: " << data << endl;

	xml.FindElem( "pressure_in" );
	data = xml.GetData();
	outfile << "Pressure: " << data << endl;	
	
	xml.OutOfElem();
      }
    
    xml.ResetPos();
    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
    outfile << "\nThe five Day Forecast are as follows: " << endl;
    while ( xml.FindElem("forecast") )
      {
	xml.IntoElem();
	xml.FindElem("simpleforecast");
	xml.IntoElem();
	xml.FindElem("forecastdays");
	xml.IntoElem();
	xml.FindElem("forecastday");

	//Second Day
	outfile << "\nThe Second Day Forecast: " << endl;
	xml.FindElem("forecastday");
	xml.IntoElem();
	xml.FindElem("date");
	xml.IntoElem();
	xml.FindElem( "pretty" );
	data  = xml.GetData();
	outfile << "Date: " << data << endl;
	xml.OutOfElem();
	xml.FindElem("high");
	xml.IntoElem();
	xml.FindElem( "fahrenheit" );
	data  = xml.GetData();
	outfile << "Temperature in Fahrenheit (High): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("low");
	xml.IntoElem();
	xml.FindElem( "fahrenheit" );
	data  = xml.GetData();
	outfile << "Temperature in Fahrenheit (Low): " << data << endl;
	xml.OutOfElem();
	xml.FindElem( "conditions" );
	data  = xml.GetData();
	outfile << "The Condition of the day: " << data << endl;
	xml.FindElem("qpf_allday");
	xml.IntoElem();
	xml.FindElem( "in" );
	data  = xml.GetData();
	outfile << "Precipitation all Day(in): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("snow_allday");
	xml.IntoElem();
	xml.FindElem( "in" );
	data  = xml.GetData();
	outfile << "Precipitation all Day(in): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("maxwind");
	xml.IntoElem();
	xml.FindElem( "mph" );
	data  = xml.GetData();
	outfile << "Max wind in (mph): " << data << endl;
	xml.OutOfElem();
	xml.FindElem( "avehumidity" );
	data  = xml.GetData();
	outfile << "Average humidity of the day: " << data << endl;
	xml.OutOfElem();

	//Third Day
	outfile << "\nThe Third Day Forecast: " << endl;
	xml.FindElem("forecastday");
	xml.IntoElem();
	xml.FindElem("date");
	xml.IntoElem();
	xml.FindElem( "pretty" );
	data  = xml.GetData();
	outfile << "Date: " << data << endl;
	xml.OutOfElem();
	xml.FindElem("high");
	xml.IntoElem();
	xml.FindElem( "fahrenheit" );
	data  = xml.GetData();
	outfile << "Temperature in Fahrenheit (High): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("low");
	xml.IntoElem();
	xml.FindElem( "fahrenheit" );
	data  = xml.GetData();
	outfile << "Temperature in Fahrenheit (Low): " << data << endl;
	xml.OutOfElem();
	xml.FindElem( "conditions" );
	data  = xml.GetData();
	outfile << "The Condition of the day: " << data << endl;
	xml.FindElem("qpf_allday");
	xml.IntoElem();
	xml.FindElem( "in" );
	data  = xml.GetData();
	outfile << "Precipitation all Day(in): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("snow_allday");
	xml.IntoElem();
	xml.FindElem( "in" );
	data  = xml.GetData();
	outfile << "Precipitation all Day(in): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("maxwind");
	xml.IntoElem();
	xml.FindElem( "mph" );
	data  = xml.GetData();
	outfile << "Max wind in (mph): " << data << endl;
	xml.OutOfElem();
	xml.FindElem( "avehumidity" );
	data  = xml.GetData();
	outfile << "Average humidity of the day: " << data << endl;
	xml.OutOfElem();

	//Fourth Day
	outfile << "\nThe Fourth Day Forecast: " << endl;
	xml.FindElem("forecastday");
	xml.IntoElem();
	xml.FindElem("date");
	xml.IntoElem();
	xml.FindElem( "pretty" );
	data  = xml.GetData();
	outfile << "Date: " << data << endl;
	xml.OutOfElem();
	xml.FindElem("high");
	xml.IntoElem();
	xml.FindElem( "fahrenheit" );
	data  = xml.GetData();
	outfile << "Temperature in Fahrenheit (High): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("low");
	xml.IntoElem();
	xml.FindElem( "fahrenheit" );
	data  = xml.GetData();
	outfile << "Temperature in Fahrenheit (Low): " << data << endl;
	xml.OutOfElem();
	xml.FindElem( "conditions" );
	data  = xml.GetData();
	outfile << "The Condition of the day: " << data << endl;
	xml.FindElem("qpf_allday");
	xml.IntoElem();
	xml.FindElem( "in" );
	data  = xml.GetData();
	outfile << "Precipitation all Day(in): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("snow_allday");
	xml.IntoElem();
	xml.FindElem( "in" );
	data  = xml.GetData();
	outfile << "Precipitation all Day(in): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("maxwind");
	xml.IntoElem();
	xml.FindElem( "mph" );
	data  = xml.GetData();
	outfile << "Max wind in (mph): " << data << endl;
	xml.OutOfElem();
	xml.FindElem( "avehumidity" );
	data  = xml.GetData();
	outfile << "Average humidity of the day: " << data << endl;
	xml.OutOfElem();

	//Fifth Day
	outfile << "\nThe Fifth Day Forecast: " << endl;
	xml.FindElem("forecastday");
	xml.IntoElem();
	xml.FindElem("date");
	xml.IntoElem();
	xml.FindElem( "pretty" );
	data  = xml.GetData();
	outfile << "Date: " << data << endl;
	xml.OutOfElem();
	xml.FindElem("high");
	xml.IntoElem();
	xml.FindElem( "fahrenheit" );
	data  = xml.GetData();
	outfile << "Temperature in Fahrenheit (High): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("low");
	xml.IntoElem();
	xml.FindElem( "fahrenheit" );
	data  = xml.GetData();
	outfile << "Temperature in Fahrenheit (Low): " << data << endl;
	xml.OutOfElem();
	xml.FindElem( "conditions" );
	data  = xml.GetData();
	outfile << "The Condition of the day: " << data << endl;
	xml.FindElem("qpf_allday");
	xml.IntoElem();
	xml.FindElem( "in" );
	data  = xml.GetData();
	outfile << "Precipitation all Day(in): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("snow_allday");
	xml.IntoElem();
	xml.FindElem( "in" );
	data  = xml.GetData();
	outfile << "Precipitation all Day(in): " << data << endl;
	xml.OutOfElem();
	xml.FindElem("maxwind");
	xml.IntoElem();
	xml.FindElem( "mph" );
	data  = xml.GetData();
	outfile << "Max wind in (mph): " << data << endl;
	xml.OutOfElem();
	xml.FindElem( "avehumidity" );
	data  = xml.GetData();
	outfile << "Average humidity of the day: " << data << endl;
	xml.OutOfElem();
	
	xml.OutOfElem();
      }

    outfile.close();

    
    char ch;


    return 0;
}
