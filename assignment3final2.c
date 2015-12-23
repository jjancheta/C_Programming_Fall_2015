// Assignment 3
// ANCHETA J. / ID # 017 433 152

// WEATHER ANALYZER version 3


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*an instance of this struct holds the weather data for a single day*/
struct DailyData{
    int day;
    int month;
    int year;
    float high;
    float low;
    float precipitation;
    char condition;
};

/*an instance of this struct holds summary information for the weather
for a given month*/
struct MonthlyStatistic{
    float minTemperature;
    float maxTemperature;
    float averageTemperature;
    float totalPrecipitation;
};

// Functions declaration

int readDailyData(FILE* fp, struct DailyData allData[]);
int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz,  struct DailyData yearData[]);
void sortYearData(struct DailyData yearData[], int sz);
void getStats(int month, const struct DailyData yearData[],int sz, struct MonthlyStatistic* monthStats);
void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly);
void graphLine(int month, const struct MonthlyStatistic* monthly);
void printVerbose(const struct DailyData yearData[],int sz);
char symbolToDraw(char condition, float avgTemp);
float average(float first, float second);
void draw( char c, int num );
void month_Word(int month, char monthConvert[]);


int main(void){
    FILE* fp = fopen("historicaldata.csv","r");
    if(!fp){
        printf("you need to put historicaldata.csv into this directory\n");
        exit(0);
    }
    struct DailyData  allData[3000];
    struct DailyData yearData[366];
    int numTotalRecords;
    
    numTotalRecords = readDailyData(fp, allData);
    int year;
    int reportType;
    int i;
    struct MonthlyStatistic monthly[12];
    
    printf("Please enter the year for the report: ");
    scanf("%d",&year);
    printf("Please enter the type of report you wish to generate:\n");
    printf("1) summary\n");
    printf("2) detailed\n");
    scanf("%d",&reportType);
    
    int numDays = getRelevantRecords(year,allData,numTotalRecords,yearData);    //getRelevantRecords output =OK
    sortYearData(yearData,numDays);                                             //sortYearData output = OK

    for(i=0;i<12;i++){
        getStats(i+1,yearData,numDays,&monthly[i]);                             // getStats output = OK
    }

    
    printf("Weather summary for %d\n",year);
    printf("|-----------|-------|-------|-------|---------|\n");
    printf("|   Month   | High  |  Low  |  Avg  | Precip  |\n");
    printf("|-----------|-------|-------|-------|---------|\n");
    
    for(i=0;i<12;i++){
        printMonthlyStatistic(i+1,&monthly[i]);                                 //printMonthlyStatatic output = OK
    }

    printf("\n\n");
    printf("Precipitation Graph\n\n");
    
    for (i=0;i<12;i++){
        graphLine(i+1,&monthly[i]);                                             //graphLine output = OK
    }
   
    if(reportType == 2){
        printf("\n\n");
        printf("Detailed report:\n");
        printVerbose(yearData,numDays);                                         //printVerbose output = OK
    }
    return 0;
}

// This function reads the data content of a file and store them in struct allData[].

int readDailyData(FILE* fp, struct DailyData allData[]){
    int i=0;
    while(fscanf(fp,"%d,%d,%d,%f,%f,%f,%c\n",
        &allData[i].year,&allData[i].month,&allData[i].day,
        &allData[i].high,&allData[i].low,&allData[i].precipitation,
        &allData[i].condition) == 7){
        i++;
    }
    return i;
}

// This function copies all records based on the year inputted by the user
// from allData[] to another struct yearData[].

int getRelevantRecords(int yearWanted, const struct DailyData allData[], 
                                    int sz,  struct DailyData yearData[]){

    int i;
    int count=0;

    for (i = 0; i < sz; i++){
        if (yearWanted == allData[i].year){
            yearData[count] = allData[i];
            count++;
        }
    }
     
    if (count == 0){
        printf("No data records found!\n");                                 // it will exit the program if no data records
        exit(0);                                                            // found in the given year
    }
    
    else { 
        return count;  
    }    
}

// This function sorts all records written in yearData[] in ascending order by month and date.

void sortYearData(struct DailyData yearData[], int sz){

    int i,j;
    struct DailyData temp;
    
    for (i = sz -1; i > 0; i--){
        
        for (j = 0; j < i; j++){
            
            if (yearData[j].month > yearData[j+1].month){               //sorting the month field
                temp = yearData[j];
                yearData[j] = yearData[j+1];
                yearData[j+1] = temp;
            }
            else if ( yearData[j].month == yearData[j+1].month){
                if (yearData[j].day > yearData[j+1].day){              //sorting the day field   
                    temp = yearData[j];
                    yearData[j] = yearData[j+1];
                    yearData[j+1] = temp;
                }        
            }
        }  
    }    
}

// This function will select the highest and lowest temperature, compute the average temperature and
// total the precipitation for each and store them in monthly[].

void getStats(int month, const struct DailyData yearData[],
                    int sz,struct MonthlyStatistic* monthly){
   
   int i, j;
   int count = 0;
   int startingPoint;
   float tempHigh;
   float tempLow;                                                             //zero is less than positive numbers.  low temps in summer are positive!!
   float totalDailyAvgTemp = 0;
   float totalPrecipitation = 0;

   for (i = 0; i < sz; i++){
        if (month == yearData[i].month && yearData[i].day == 1){             //first value of the month
            startingPoint = i;
            tempLow = yearData[i].low;
            tempHigh = yearData[i].high;
            i = sz;
        }    
   }

   for (j = startingPoint; j < sz; j++){
        if(month == yearData[j].month){
            count++;                                                          //number of days per month                                                        
            totalDailyAvgTemp += average(yearData[j].high, yearData[j].low);
            totalPrecipitation += yearData[j].precipitation;                

            if (yearData[j].high > tempHigh){
                tempHigh = yearData[j].high;
            }

            if (yearData[j].low < tempLow){
                tempLow = yearData[j].low;
            }        
        }   
    }

    if (count > 0){
        monthly->minTemperature = tempLow;
        monthly->maxTemperature = tempHigh;
        monthly->averageTemperature = totalDailyAvgTemp / count;
        monthly->totalPrecipitation = totalPrecipitation;
    }
    else {                                                    // if no records available for certain month/s
        monthly->minTemperature = 0;                          // for the year selected, it will assign zero values
        monthly->maxTemperature = 0;                          // to all MonthlyStatistic members
        monthly->averageTemperature = 0;                        
        monthly->totalPrecipitation = 0;
    }   
}

// This function prints the months in word, highest and lowest temperature, average temperation and total
// precipitation per month in tabular format.

void printMonthlyStatistic(int month,const struct MonthlyStatistic* monthly){
    
    char monthWords[10];
    
    if (monthly->maxTemperature != 0 && monthly->minTemperature != 0 && monthly->averageTemperature != 0
                                    && monthly->totalPrecipitation != 0){                   // it will not print month without records
        
        month_Word(month, monthWords);
        printf("|%10s | %-5.1f | %-5.1f | %-5.1f | %-5.1f   |\n", monthWords, monthly->maxTemperature,
                                                                            monthly->minTemperature,
                                                                            monthly->averageTemperature,
                                                                            monthly->totalPrecipitation);
    }    
}

// This function prints the graph of the total precipitation each month using a '*' symbol.

void graphLine(int month,const struct MonthlyStatistic* monthly){
    
    int starsQty;
    char monthWords[10];
    
    if (monthly->maxTemperature != 0 && monthly->minTemperature != 0 && monthly->averageTemperature != 0
                                    && monthly->totalPrecipitation != 0){                 // it will not print month without records
        month_Word(month, monthWords);
        starsQty = (int)(monthly->totalPrecipitation / 10 + 0.5);
        printf("%10s |", monthWords);
        draw ('*',starsQty);
    }    
}

// This function prints the month in word, date, year, average daily temperature and
// corresponding symbol for whole selected year by the user.

void printVerbose(const struct DailyData yearData[],int sz){
    
    int i;
    float dailyAvg = 0;
    char monthWords[10];

    for (i = 0; i < sz; i++){
        month_Word(yearData[i].month, monthWords);
        dailyAvg = average (yearData[i].high, yearData[i].low);
        printf("%10s %2d %d: %5.1f ", monthWords, yearData[i].day, yearData[i].year, dailyAvg);
        draw(symbolToDraw(yearData[i].condition, dailyAvg), 20); 
    } 
}

// This function selects which character to print depending on the condition 
// and the computed average temperature.

char symbolToDraw(char condition, float avgTemp){
   
    char symbolFunction5;

    if (condition == 's')
        symbolFunction5 = '@';
    
    else if (condition == 'c')
        symbolFunction5 = '~';
    
    else if (condition == 'p' && avgTemp <= 0)   
        symbolFunction5 = '*';
    
    else
        symbolFunction5 = ';';
    
    return symbolFunction5;
}

//This function calculates and returns the daily average temperature.

float average(float first, float second){
    
    float dailyAvgFunction3 = 0;

    dailyAvgFunction3 = (first + second) / 2;

    return dailyAvgFunction3;
}

//This function prints row of character with a specified number.

void draw( char c, int num ){
   
    int i;

    for (i = 0; i < num; i++){
        printf("%c", c);

    }
    
    printf("\n");
}

// This function selects and returns the corresponding month in words of a given month number.

void month_Word(int month, char monthConvert[]){

    int i;
    char monthWords[12][10] ={ "January","February","March","April","May","June","July",
                                "August","September","October","November","December" };
    
    for (i = 0; i < 12; i++){
        if (month == i + 1){
           strcpy (monthConvert, monthWords[i]);
           i = 12; 
        }    
    }    
}   


/* I declare that the attached assignment is wholly my own work in accordance with Seneca Academic Policy.
No part of this assignment has been copied manually or electronically from any source (including web sites) or
distributed to other students.

Name:  ANCHETA, JESUS JR     ID:  017 433 152 */

