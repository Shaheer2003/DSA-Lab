    #include <iostream>
#include <string>
using namespace std;

class Date{
    public:
    int day, month, year;

    Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
};

    void selectionSort(Date arr[], int size){
        for(int i = 0; i < size - 1; i++){
            int minIndex = i;
            for(int j = i + 1; j < size; j++){
                if(arr[j].year < arr[minIndex].year)
                {
                    minIndex = j;
                }
                else if(arr[j].year == arr[minIndex].year && arr[j].month < arr[minIndex].month)
                {
                    minIndex = j;
                }
                else if(arr[j].year == arr[minIndex].year && arr[j].month == arr[minIndex].month && arr[j].day < arr[minIndex].day)
                {
                    minIndex = j;
                }
            }
            if(i != minIndex){
                swap(arr[i], arr[minIndex]);
            }
        }
    }



int main(){
    Date dates[5] = {Date(27,02,2003),Date(12,02,2003),Date(15,01,2000),Date(01,12,2020),Date(9,10,1990)};
    selectionSort(dates,5);
    for(int i = 0; i < 5; i++){
        cout << dates[i].day << "/" << dates[i].month << "/" << dates[i].year << endl;
    }
}