#include <stdio.h>
#include <string.h>

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

int readDailyData(FILE* fp, struct DailyData allData[]);

int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz,  struct DailyData yearData[]);
void sortYearData(struct DailyData yearData[], int sz);
void getStats(int month, const struct DailyData yearData[],
                    int sz, struct MonthlyStatistic* monthStats);
void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly);
void graphLine(int month, const struct MonthlyStatistic* monthly);
void printVerbose(const struct DailyData yearData[],int sz);
char symbolToDraw(char condition, float avgTemp);
float average(float first, float second);
void draw( char c, int num );
void month_Word(int month, char monthConvert[]);




int main(void){
    FILE* fp = fopen("historicaldata.csv","r");
    struct DailyData  allData[3000];
    struct DailyData yearData[366];
    int numTotalRecords;
    numTotalRecords = readDailyData(fp, allData);
    int year;
    int reportType;
    struct MonthlyStatistic monthly[12];
    
    printf("Please enter the year for the report: ");
    scanf("%d",&year);
    printf("Please enter the type of report you wish to generate:\n");
    printf("1) summary\n");
    printf("2) detailed\n");
    scanf("%d",&reportType);
    
    int numDays = getRelevantRecords(year,allData,numTotalRecords,yearData);

    /*int j;

    printf("\nUNSORTED RECORDS\n");

    for(j=0; j < numDays; j++){      //test getRelevantRecords output =OK

        printf("%d,%d,%d,%f,%f,%f,%c\n",yearData[j].year,yearData[j].month,yearData[j].day,
                                        yearData[j].high,yearData[j].low,yearData[j].precipitation,
                                        yearData[j].condition);   
    }*/

    sortYearData(yearData,numDays);


    /*printf("\nSORTED RECORDS\n");

    for(j=0; j < numDays; j++){      //test sortYearData output =

        printf("%d,%d,%d,%f,%f,%f,%c\n",yearData[j].year,yearData[j].month,yearData[j].day,
                                        yearData[j].high,yearData[j].low,yearData[j].precipitation,
                                        yearData[j].condition);   
    }*/



    for(int i=0;i<12;i++){
        getStats(i+1,yearData,numDays,&monthly[i]);           //what does it mean &monthly[i]?
    }

    
    printf("\nWeather summary for %d\n\n",year);
    printf("|-----------|-------|-------|-------|---------|\n");
    printf("|   Month   | High  |  Low  |  Avg  | Precip  |\n");
    printf("|-----------|-------|-------|-------|---------|\n");
    
    for(int i=0;i<12;i++){
        printMonthlyStatistic(i+1,&monthly[i]);
    }
    
    printf("\n\n");
    printf("Precipitation Graph\n\n");
    
    for (int i=0;i<12;i++){
        graphLine(i+1,&monthly[i]);
    }
   
    if(reportType == 2){
        printf("\n\n");
        printf("Detailed report:\n");
        printVerbose(yearData,numDays);
    }
    return 0;
}

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


int getRelevantRecords(int yearWanted, const struct DailyData allData[], 
                                    int sz,  struct DailyData yearData[]){

    int i;
    int count=0;

    for (i = 0; i < sz; i++){

        if (yearWanted == allData[i].year){
            yearData[count].year = allData[i].year;
            yearData[count].month = allData[i].month;
            yearData[count].day = allData[i].day;
            yearData[count].high = allData[i].high;
            yearData[count].low = allData[i].low;
            yearData[count].precipitation = allData[i].precipitation;
            yearData[count].condition = allData[i].condition;
            count++;
        }
    }
    
    return count;
    
}

void sortYearData(struct DailyData yearData[], int sz){

    int i,j, k;
    int tempYear, tempMonth, tempDay;
    float tempHigh, tempLow, tempPrecipication;
    char tempCondition;

    for (i = sz -1; i > 0; i--){
        
        for (j = 0; j < i; j++){
            
            if (yearData[j].month > yearData[j+1].month){
                tempMonth = yearData[j].month;
                yearData[j].month = yearData[j+1].month;
                yearData[j+1].month = tempMonth;
        
                tempDay = yearData[j].day;
                yearData[j].day = yearData[j+1].day;
                yearData[j+1].day = tempDay;

                tempHigh = yearData[j].high;
                yearData[j].high = yearData[j+1].high;
                yearData[j+1].high = tempHigh;

                tempLow = yearData[j].low;
                yearData[j].low = yearData[j+1].low;
                yearData[j+1].low = tempLow;

                tempPrecipication = yearData[j].precipitation;
                yearData[j].precipitation = yearData[j+1].precipitation;
                yearData[j+1].precipitation = tempPrecipication;

                tempCondition = yearData[j].condition;
                yearData[j].condition = yearData[j+1].condition;
                yearData[j+1].condition = tempCondition;

            }
            
            else if ( yearData[j].month == yearData[j+1].month){
                
                if (yearData[j].day > yearData[j+1].day){
                    tempDay = yearData[j].day;
                    yearData[j].day = yearData[j+1].day;
                    yearData[j+1].day = tempDay;

                    tempHigh = yearData[j].high;
                    yearData[j].high = yearData[j+1].high;
                    yearData[j+1].high = tempHigh;

                    tempLow = yearData[j].low;
                    yearData[j].low = yearData[j+1].low;
                    yearData[j+1].low = tempLow;

                    tempPrecipication = yearData[j].precipitation;
                    yearData[j].precipitation = yearData[j+1].precipitation;
                    yearData[j+1].precipitation = tempPrecipication;

                    tempCondition = yearData[j].condition;
                    yearData[j].condition = yearData[j+1].condition;
                    yearData[j+1].condition = tempCondition;
                }        
            }
        }  
    }    

}

void getStats(int month, const struct DailyData yearData[],
                    int sz,struct MonthlyStatistic* monthly){
   
   int i, j, count=0;
   int startingPoint;
   float tempHigh;
   float tempLow;                              //  zero is less than positive numbers.  low temps summer are positive
   float totalDailyAvgTemp = 0;
   float totalPrecipitation = 0;

   for (j = 0; j < sz; j++){
        if (month == yearData[j].month && yearData[j].day == 1){       //first value of the month
            startingPoint = j;
            tempLow = yearData[j].low;
            tempHigh = yearData[j].high;
            j = sz;
        }    
   }

   for (i = startingPoint; i < sz; i++){


        if(month == yearData[i].month){

            count++;                                       //number of days per month                                                        
            totalDailyAvgTemp += (yearData[i].high + yearData[i].low) / 2;
            totalPrecipitation += yearData[i].precipitation;                

            if (yearData[i].high > tempHigh){
                tempHigh = yearData[i].high;
            }

            if (yearData[i].low < tempLow){
                tempLow = yearData[i].low;
            }        
            
        }   
            
    }

    //printf("month = %d, %.1f, %.1f, %.1f, %.1f\n", month, tempHigh, tempLow,totalDailyAvgTemp/count, totalPrecipitation);

    monthly->minTemperature = tempLow;
    monthly->maxTemperature = tempHigh;
    monthly->averageTemperature = totalDailyAvgTemp / count;
    monthly->totalPrecipitation = totalPrecipitation;

}


void printMonthlyStatistic(int month,const struct MonthlyStatistic* monthly){
    
    char monthWords[10];

    month_Word(month, monthWords);
    
    printf("|%10s | %-5.1f | %-5.1f | %-5.1f | %-5.1f   |\n", monthWords, monthly->maxTemperature,
                                                                        monthly->minTemperature,
                                                                        monthly->averageTemperature,
                                                                        monthly->totalPrecipitation);
    printf("|-----------|-------|-------|-------|---------|\n");

}


void graphLine(int month,const struct MonthlyStatistic* monthly){
    
    int i;
    int starsQty;

    char monthWords[10];
    
    month_Word(month, monthWords);
    
    starsQty = (int)(monthly->totalPrecipitation / 10 + 0.5);
    printf("%10s |", monthWords);
    draw ('*',starsQty);
}


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

char symbolToDraw(char condition, float avgTemp){
   
   char symbolFunction5;

    if (condition == 's')
        symbolFunction5 = '@';
    
    else if (condition == 'c')
        symbolFunction5 = '~';
    
    else if (condition == 'p' && avgTemp <= 0)   // assignment 2 avgTemp <= 0;  assignment3 < 0 ??
        symbolFunction5 = '*';
    
    else
        symbolFunction5 = ';';

    
    return symbolFunction5;
}

float average(float first, float second){
    
    float dailyAvgFunction3 = 0;

    dailyAvgFunction3 = (first + second) / 2;

    return dailyAvgFunction3;
}

void draw( char c, int num ){
   
   int i;

    for (i = 0; i < num; i++){
        printf("%c", c);

    }
    
    printf("\n");
}



void month_Word(int month, char monthConvert[]){

    int i;
    char monthWords[12][10] ={
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "Septemper",
            "October",
            "November",
            "December",
        };

    for (i = 0; i < 12; i++){
        if (month == i + 1)
           strcpy (monthConvert, monthWords[i]);
    }
      
}    
