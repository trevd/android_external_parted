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
    
    if (argc != 3)
        errx (EXIT_FAILURE,"wrong number of arguments");
    
    
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
    
    part = ped_disk_get_partition(disk,atoi(argv[2]));
    if (part == NULL)
        goto error_destroy_disk;
    
     printf("Removing Partition:%d\n",part->num);
     if(!ped_disk_delete_partition(disk,part)){
         printf("ERROR : Removing Partition:%d\n",part->num);
         ped_partition_destroy(part);
         goto error_destroy_disk;
     }
    if(!ped_disk_commit_to_dev(disk)){
         printf("ERROR : ped_disk_commit_to_dev\n");
         goto error_destroy_disk;
    }
         
    return_code = EXIT_SUCCESS;    
        	
        
    
   
error_destroy_disk:
     ped_disk_destroy (disk);
// Fall through to clean up 
error_destroy_device:
    ped_device_destroy (device);

error_exit:
    return return_code;
}