#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <algorithm>

using namespace std ;

ios::openmode mode = ios::in | ios::out | ios::binary ;

string four_screen, nine_screen ;
string four_clear = "0" ;
unsigned int switch_sleep_cycle = 50000 ; // Microseconds between switch events.
unsigned int main_sleep_cycle = 30000 ; // Microseconds between main function cycles.

int main()
{
cout << "Starting" << endl ;
while(true)
{
    fstream four_scr_stream ("rims_config/four_screen.txt", mode) ;
    fstream nine_scr_stream ("rims_config/nine_screen.txt", mode) ;
    cout << "filestreams loaded\n" ;
    four_scr_stream >> four_screen ;
    nine_scr_stream >> nine_screen ;

    if ( four_screen == "1" ) 
    {
        system("dconf write  /org/compiz/profiles/unity/plugins/core/hsize 2") ;
        system("dconf write  /org/compiz/profiles/unity/plugins/core/vsize 2") ;
        

        system("wmctrl -o 0,0") ; // Switch to Workspace 6.
        system("wmctrl -r firefox -e '0,0,0, 200, 200'") ;
        usleep(switch_sleep_cycle) ;

        cout << "Four Screen Executed\n" ;
    }

    if ( nine_screen == "1" )
    {
        system("dconf write  /org/compiz/profiles/unity/plugins/core/hsize 3") ;
        system("dconf write  /org/compiz/profiles/unity/plugins/core/vsize 3") ;
        

        system("wmctrl -o 2881,0") ; // Switch to Workspace 3.
        system("wmctrl -r Android1 -e '0,0,0, 200, 200'") ; // Move Android1 to current viewport.
        usleep(switch_sleep_cycle) ;

        system("wmctrl -o 2881,1000") ; // Switch to Workspace 6.
        system("wmctrl -r firefox -e '0,0,0, 200, 200'") ;
        usleep(switch_sleep_cycle) ;

        system("wmctrl -o 1281,2000") ; // Switch to Workspace 7.
        system("wmctrl -r Aircast1 -e '0,0,0, 200, 200'") ;
        usleep(switch_sleep_cycle) ;

        system("wmctrl -o 2281,2000") ; // Switch to Workspace 8.
        system("wmctrl -r code -e '0,0,0, 200, 200'") ;
        usleep(switch_sleep_cycle) ;

        cout << "Nine Screen Executed\n" ;
    }

usleep(main_sleep_cycle) ;
}
return 0 ;
}