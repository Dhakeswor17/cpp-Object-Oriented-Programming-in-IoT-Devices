#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <algorithm>
#pragma warning (disable:4996)


using namespace std;
class Animal{
private:
    string Type;
    string Name;
    int Number;
public:
    void setName(string name){
        Name = name;
    }
        string  getName(){
            return Name;
    }
    void setName(int number){
         if(number<18)
        Number = Number ;
    }
    int getAge(){
        return Number;
    }



    void spices(){

        cout<<Type<<Name<<Number<<endl;

    }
    Animal(string type, string name, int number){
        Type = type;
       Name = name;
       Number = number;


    }

};
int main(){

    Animal eat = Animal("cat ", "roll number is ", 7);

    Animal eat1 = Animal("fog ", "number is ", 55);
   eat.spices();
   eat1.spices();



}