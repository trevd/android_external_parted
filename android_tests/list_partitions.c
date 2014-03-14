/*
 * probe.c
 * 
 * Copyright 2013 Trevor Drake <trevd1234@gmail.com>
 * 
 * This program is free software;
 you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation;
 either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY;
 without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program;
 if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <parted/parted.h>
int main (int argc, char* argv[])
{
    PedDevice* device = NULL;
    PedDisk* disk = NULL;
    PedDiskType* type = NULL;
    PedPartition* part = NULL;
    
    int return_code = EXIT_FAILURE;
    
	if (argc != 2){
	    printf("wrong number of arguments\n");
	    return EXIT_FAILURE;
	}
    
    
    device = ped_device_get (argv[1]);
    printf("device:%s\n",argv[1]);
    if (device == NULL)
        goto error_exit;
    
    type = ped_disk_probe (device);
    if (type == NULL) 
        goto error_destroy_device;
        
    printf("Disk Type:%s\n",type->name);
        
    
    disk = ped_disk_new (device);
    if (disk == NULL)
        goto error_destroy_device;
    
    do
    {
        if ((part = ped_disk_next_partition (disk, part)) && (part->num > -1) )
                printf("%d %s %s\n",part->num,ped_partition_type_get_name(part->type),ped_unit_format (device,part->geom.length));
        
    }while( part );
    
    ped_disk_destroy (disk);
    return_code = EXIT_SUCCESS;
    
// Fall through to clean up 
error_destroy_device:
    ped_device_destroy (device);

error_exit:
    return return_code;
}
