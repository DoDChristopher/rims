#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>

using namespace std ;

string prog_check ;

ios::openmode mode = ios::in | ios::out | ios::binary ;

int firefox_pid, audacity_pid, vmware_pid, vlc_pid = 1 ; // Declare process id variables

int main()
{
    
    while(true) 
    {
        fstream key_1_str ("/home/chris/Desktop/rims_control_suite/bin/prog_check.txt", mode) ;
        key_1_str >> prog_check ;

        if ( prog_check == "1" )
        {
            // Obtain process id. Null equals 256.
            firefox_pid = system("pidof firefox") ; 

            if ( firefox_pid == 256 ) // If not running.
            {        
                cout << "Starting Firefox" << endl ;
                system("firefox_start") ; // System call bash script to start program.
            }
            else // If running.
            {
                cout << "Firefox already running." << endl ;
            }


            // Obtain process id. Null equals 256.
            audacity_pid = system("pidof audacity") ; 

            if ( audacity_pid == 256 ) // If not running.
            {        
                cout << "Starting Audacity" << endl ;
                system("Audacity") ; // System call bash script to start program.
            }
            else // If running.
            {
                cout << "Audacity already running." << endl ;
            }


            // Obtain process id. Null equals 256.
            vmware_pid = system("pidof vmware") ; 

            if ( vmware_pid == 256 ) // If not running.
            {        
                cout << "Starting VMWare" << endl ;
                system("vmware_start") ; // System call bash script to start program.
            }
            else // If running.
            {
                cout << "VMWare already running." << endl ;
            }


            // Obtain process id. Null equals 256.
            vlc_pid = system("pidof vlc") ; 

            if ( vlc_pid == 256 ) // If not running.
            {        
                cout << "Starting Ultrasound" << endl ;
                system("vlc_start") ; // System call bash script to start program.
            }
            else // If running.
            {
                cout << "Ultrasound already running." << endl ;
            }

        }

        sleep(1) ;

    }


}