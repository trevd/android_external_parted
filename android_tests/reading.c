#include <stdio.h>
#include <parted/parted.h>
int main (int argc, char* argv[])
{
        char* size;
        PedDevice* device;
        char* transport[13] = {"unknown", "scsi", "ide", "dac960", "cpqarray","file", "ataraid", "i2o", "ubd", "dasd", "viodasd","sx8", "dm"};
   
        if (argc != 2) { 
                printf ("wrong number of arguments\n");
                goto error;
        }
                
        device = ped_device_get (argv[1]);
        if (device == NULL) goto error;
        
        size = ped_unit_format_byte (device, device->length * device->sector_size);
        
        if (size == NULL) goto error;
        
        printf("Model: %s\n", device->model);
        printf("Type: %d\n", device->type);
        printf("Size: %s\n", size);
        printf("Sector size (logical/physical): %lldB/%lldB\n",device->sector_size,device->phys_sector_size);
        free (size);
        free (device);
        return 0;
error:
        return 1;
}
