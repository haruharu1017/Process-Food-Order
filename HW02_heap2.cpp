#include <iostream>
#include <queue>
#include <thread>
using namespace std;

struct FoodOrder{
    public:
    string name;
    int priority;

    FoodOrder(string n, int p):name(n),priority(p){}

//the operator needs to be <
    bool operator <(const FoodOrder & food)const{
        return (priority<food.priority);
    }
};

void processOrder(priority_queue<FoodOrder> orderQueue){
    cout<<"Restaurant Orders:"<<endl;
    while(!orderQueue.empty()){
        cout<<"Preparing "<< orderQueue.top().name 
        <<"("<<"Priority: "<<orderQueue.top().priority<<")"<<endl;

        this_thread::sleep_for(chrono::seconds(2));

        cout<<"Order for"<<orderQueue.top().name
        <<"("<<"Priority: "<<orderQueue.top().priority<<") is ready."<<endl;

        orderQueue.pop();
    }
}

int main(){
    priority_queue<FoodOrder> orderQueue;
    int numberOfFood;
    orderQueue.push(FoodOrder("Pizza",3));
    orderQueue.push(FoodOrder("Burger", 2));
    orderQueue.push(FoodOrder("Salad", 1));
    orderQueue.push(FoodOrder("Pasta", 3));
    orderQueue.push(FoodOrder("Ice Cream", 2));
    processOrder(orderQueue);
}