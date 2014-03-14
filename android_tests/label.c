#include <stdio.h>
#include <parted/parted.h>
int main (int argc, char* argv[])
{
        PedDiskType* type;
        for (type = ped_disk_type_get_next (NULL); type;
        type = ped_disk_type_get_next (type))
        puts (type->name);
        return 0;
}
