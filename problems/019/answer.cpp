#include <iostream>
#include <string>

using namespace std;

char days[] = {'s', 'm', 't', 'w', 'h', 'f'};
int day_index = -1;

void increment_day(){
  if (day_index == -1){
    day_index = 2; // because jan 1st 1901 was a tuesday!
  } else if (day_index == 6){
    day_index = 0;
  } else {
    day_index++;
  }
}

char getDayName(){
  return days[day_index];
}

int main(){

  // just build up info for a big loop
  int days_in_year = 365;
  int current_year = 1901;
  int our_special_case = 0; // where we will count the days that land on months

  // count years here:
  while (current_year < 2001){
    int day = 0;

    // count days here:
    if (current_year%4 == 0){
      // leap year!
      while(day != days_in_year+1){

        if (day <= 31){ // january
                if (!day_index && day == 1) our_special_case++;
        } else if (day <= (31 + 29)){ // febuary
 if (!day_index && day == (31 + 1)) our_special_case++;
        } else if (day <= (31 + 29 + 31)){ // march
 if (!day_index && day == (31 + 29 + 1)) our_special_case++;
        } else if (day <= (31 + 29 + 31 + 30)){ // april
 if (!day_index && day == (31 + 29 + 31 + 1)) our_special_case++;
        } else if (day <= (31 + 29 + 31 + 30 + 31)){ // may
 if (!day_index && day == (31 + 29 + 31 + 30 + 1)) our_special_case++;
        } else if (day <= (31 + 29 + 31 + 30 + 31 + 30)){ // june
 if (!day_index && day == (31 + 29 + 31 + 30 + 31 + 1)) our_special_case++;
        } else if (day <= (31 + 29 + 31 + 30 + 31 + 30 + 31)){ // july
 if (!day_index && day == (31 + 29 + 31 + 30 + 31 + 30 + 1)) our_special_case++;
        } else if (day <= (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31)){ // august
 if (!day_index && day == (31 + 29 + 31 + 30 + 31 + 30 + 31 + 1)) our_special_case++;
        } else if (day <= (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30)){ // september
 if (!day_index && day == (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 1)) our_special_case++;
        } else if (day <= (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31)){ // october
 if (!day_index && day == (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 1)) our_special_case++;
        } else if (day <= (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30)){ // november
 if (!day_index && day == (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 1)) our_special_case++;
        } else if (day <= (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31)){ // december
 if (!day_index && day == (31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 1)) our_special_case++;
        }

        increment_day();
        day++;


      }
    } else {
      // normal year
      while(day != days_in_year){

        if (day <= 31){ // january
                if (!day_index && day == 1) our_special_case++;
        } else if (day <= (31 + 28)){ // febuary
 if (!day_index && day == (31 + 1)) our_special_case++;
        } else if (day <= (31 + 28 + 31)){ // march
 if (!day_index && day == (31 + 28 + 1)) our_special_case++;
        } else if (day <= (31 + 28 + 31 + 30)){ // april
 if (!day_index && day == (31 + 28 + 31 + 1)) our_special_case++;
        } else if (day <= (31 + 28 + 31 + 30 + 31)){ // may
 if (!day_index && day == (31 + 28 + 31 + 30 + 1)) our_special_case++;
        } else if (day <= (31 + 28 + 31 + 30 + 31 + 30)){ // june
 if (!day_index && day == (31 + 28 + 31 + 30 + 31 + 1)) our_special_case++;
        } else if (day <= (31 + 28 + 31 + 30 + 31 + 30 + 31)){ // july
 if (!day_index && day == (31 + 28 + 31 + 30 + 31 + 30 + 1)) our_special_case++;
        } else if (day <= (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31)){ // august
 if (!day_index && day == (31 + 28 + 31 + 30 + 31 + 30 + 31 + 1)) our_special_case++;
        } else if (day <= (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30)){ // september
 if (!day_index && day == (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 1)) our_special_case++;
        } else if (day <= (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31)){ // october
 if (!day_index && day == (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 1)) our_special_case++;
        } else if (day <= (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30)){ // november
 if (!day_index && day == (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 1)) our_special_case++;
        } else if (day <= (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31)){ // december
 if (!day_index && day == (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 1)) our_special_case++;
        }

        increment_day();
        day++;

      }
    }


    current_year ++;
  }

  cout << "special case: " << our_special_case << endl;
  // bam

  return 0;
}
