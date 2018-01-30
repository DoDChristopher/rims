#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <algorithm>

using namespace std ;

string pid_bulk_list,  pid_vm1, pid_vm2, pid_vm3, pid_vm4 ;

char pid_bulk_list_last[20] ;

unsigned int main_sleep_cycle = 100000 ; // Microseconds between main function cycles.

int vm1_used = 0 ;  //
int vm2_used = 0 ;  // Indicates weather or not the PID for specific machine
int vm3_used = 0 ;  // has been assigned or not.
int vm4_used = 0 ;  //


int main()
{

    while (true) 
    {
        pid_bulk_list = system("pidof vmware") ; // check the PID's under name "vmware"

        if ( pid_bulk_list.compare(pid_bulk_list_last) != 0 )
        {

            for (unsigned int i = 0; i < strlen(pid_bulk_list_last); ++i)  // For loop that cycles once for each character in the string 'pid_bulk_list_last'
            {
            pid_bulk_list.erase (std::remove(pid_bulk_list.begin(), pid_bulk_list.end(), pid_bulk_list_last[i]), pid_bulk_list.end());
            }


            cout << pid_bulk_list << endl ;
        
        
        }

        usleep(main_sleep_cycle) ;
    }

}