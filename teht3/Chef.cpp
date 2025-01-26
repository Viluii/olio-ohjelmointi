#include "Chef.h"


Chef::Chef(string chefName) {
    this->chefName = chefName;
}
int Chef::makeSalad(int salad){
    return salad/5;
}
int Chef::makeSoup(int soup){
    return soup/3;
}
string Chef::getName(){
    return chefName;
}
Chef::~Chef(){
    cout<<chefName<<" destructor"<<endl;
}
