#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <windows.h>

#define temp_rand   ((rand() % 256) - 128)
#define humid_rand  (rand() % 101)
#define batt        (rand() % 2)
#define c_1         1000
#define clock_step  3
#define sen_id      5
#define sleep       3000
#define in8       8
#define in7       7
#define in12      12
#define in1       1



#pragma pack(push,1)
struct SensorRecord
{
    uint8_t  sensorID   : in8;   // 1 byte
    uint16_t timestamp  : in12;  // 1.5 bytes
    int8_t   temperature: in8;   // 1 byte
    uint8_t  humidity   : in7;   // <1 byte
    uint8_t  battery    : in1;   // <1 byte
}; // total = 36 bits = 5 bytes
#pragma pack(pop)

int read_size()
{
    struct SensorRecord rec;
    printf("Size of SensorRecord = %zu bytes\n", sizeof(rec));
    return 0;
}

void record_file(FILE *fp,  struct SensorRecord *rec)
{
    fwrite(rec,sizeof(*rec),1,fp);
}

void print_record( struct SensorRecord *rec) {
    printf("Sensor %u | Time %u sec | Temp %d°C | battery %u | Humidity %u%%\n",
           rec->sensorID, rec->timestamp, rec->temperature, rec->battery,rec->humidity);
}

void find_max(FILE *fp)
{
    struct SensorRecord rec;
    struct SensorRecord maxtemp ={0};
    struct SensorRecord maxhum ={0};
    rewind(fp);

    while(fread(&rec, sizeof(rec),1,fp))
    {
        if(rec.temperature > maxtemp.temperature)
            maxtemp = rec;
        if(rec.humidity > maxhum.humidity)
            maxhum = rec;
    }

    printf("Highest Temp and Humid: \n");
    printf("Highest Temp\n");
    printf("Sensor ID: %u\n Time: %u seconds \n battery: %u \n Temperature: %d\n",
           maxtemp.sensorID, maxtemp.timestamp, maxtemp.battery, maxtemp.temperature);
    printf("Highest Humid\n");
    printf("Sensor ID: %u\n Time: %u seconds \n battery: %u \n Humidity: %u\n",
           maxhum.sensorID, maxhum.timestamp, maxhum.battery, maxhum.humidity);
}

int main()
{
    srand(time(NULL));
    struct SensorRecord rec;

    FILE* fp = fopen("sensor.bin","wb+");
    if (!fp)
    {
        perror("File not found!!!");
        return 1;
    }

    for(uint16_t Clock = 0; Clock < c_1; Clock += clock_step)
    {
        for(uint8_t id = 0; id < sen_id; id++)
        {
            rec.sensorID    = id;
            rec.timestamp   = Clock;
            rec.temperature = temp_rand;
            rec.humidity    = humid_rand; // 0–100
            rec.battery     = batt;

            record_file(fp,&rec);
            print_record(&rec);
        }
        printf("\n");
       //Sleep(sleep);
    }

    find_max(fp);

    fclose(fp);
    read_size();
    return 0;
}

