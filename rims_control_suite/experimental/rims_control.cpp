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
        fstream guar_state ("guardian_state.txt", mode) ;
        fstream make_exist ("make_update/makefile1", mode) ;
        fstream update_mode ("rims_config/update_mode.txt", mode) ;

        guar_state >> prog_check ;
        

        if ( make_exist )
        {
            cout << endl << "Make found" << endl ;
            update_mode << "1" ;
            system("reboot") ;
        }

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
        else
        {
        cout << "off" << endl ;
        }

        sleep(1) ;

    }


}