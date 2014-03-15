#include <stdio.h>
#include <parted/parted.h>
int main (int argc, char* argv[])
{
        
        PedDevice* device;
        
          
        if (argc != 2) { 
                printf ("wrong number of arguments\n");
                goto error;
        }
                
        device = ped_device_get (argv[1]);
        if (device == NULL) goto error;
        
        // Get the default unit
        PedUnit unit = ped_unit_get_default();
        const char* unit_name = ped_unit_get_name(unit);
        printf("Default Unit Name = %s ( %d )\n",unit_name,unit);
        //free((void*)unit_name);
        
        ped_unit_set_default(PED_UNIT_MEGABYTE);
        
        unit = ped_unit_get_default();
        const char* new_unit_name = ped_unit_get_name(unit);
        printf("New Default Unit Name = %s ( %d )\n",new_unit_name,unit);
        //free(new_unit_name);
        
        char* size = ped_unit_format_byte (device, device->length * device->sector_size);
        if (size == NULL) goto error;
        printf("Size: %s\n", size);
        
        ped_device_destroy(device);
        
        return 0;
error:
        return 1;
}
