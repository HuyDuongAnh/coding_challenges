// URL link: https://docs.kernel.org/driver-api/thermal/sysfs-api.html

/* Thermal_zone_device interface 
struct thermal_zone_device
*thermal_zone_device_register(char *type,
                              int trips, int mask, void *devdata,
                              struct thermal_zone_device_ops *ops,
                              const struct thermal_zone_params *tzp,
                              int passive_delay, int polling_delay))

Adds a new thermal zon device (sensor) to /sys/class/thermal folder as thermal_zone. It tries
to bind all the thermal cooling devices registered at the same time.
*/

void set_up_thermal_sysfs_driver(void){
    struct thermal_zone_device * tzd;
    tzd = thermal_zone_device_register()
}

int main(void){
    return 0;
}