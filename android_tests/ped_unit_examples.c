#include <stdio.h>
#include <parted/parted.h>
int main (int argc, char* argv[])
{
        char* size;
        PedDevice* device;
        
          
        if (argc != 2) { 
                printf ("wrong number of arguments\n");
                goto error;
        }
                
        device = ped_device_get (argv[1]);
        if (device == NULL) goto error;
        
        PedUnit unit = ped_unit_get_default();
        const char* unit_name = ped_unit_get_name(unit);
        printf("Default Unit Name = %s ( %d )\n",unit_name,unit);
        ped_device_destroy(device);
        
        return 0;
error:
        return 1;
}
