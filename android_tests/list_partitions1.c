#include <err.h>
#include <stdio.h>
#include <parted/parted.h>
int main (int argc, char* argv[])
{
	PedDevice* device;
	PedDisk* disk;
	PedPartition* part;
	if (argc != 2){
	    printf("wrong number of arguments\n");
	    return EXIT_FAILURE;
	}
	
	device = ped_device_get (argv[1]);
	if (device == NULL)
	    goto error;
	
	disk = ped_disk_new (device);
	if (disk == NULL)
	    goto error_destroy_device;
	
	printf ("%3s  %s  %s  %s\n", "no.", "start", "size", "fs");
	for (part = ped_disk_next_partition (disk, NULL);part;part = ped_disk_next_partition (disk, part)){
		if (part->num < 0)
			continue;
		printf ("=  %lld  %lld  %s\n", 	part->num,
										part->geom.start,
										part->geom.length,
										(part->fs_type) ? part->fs_type->name : "");
	}
	ped_disk_destroy (disk);
	ped_device_destroy (device);
	return 0;
error_destroy_device:  
	ped_device_destroy (device);
error:
	return 1;
}
