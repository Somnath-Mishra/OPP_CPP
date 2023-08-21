#include <iostream>
#include<cmath>
using namespace std;
class wirelessDevice{
    private:
    float localX,localY;
    int id;
    float circularRange;
    public:
    wirelessDevice(float localX,float localY,int id,float circularRange){
        this->localX=localX;
        this->localY=localY;
        this->id=id;
        this->circularRange=circularRange;
    }
    int get_id(){
        return id;
    }
    void setLocation(float x,float y){
        this->localX=x;
        this->localY=y;
    }
    bool neighbour(wirelessDevice d){
        float dist=static_cast<float>(sqrt((localX-d.localX)*(localX-d.localX)+(localY-d.localY)*(localY-d.localY)));
        if(dist<=circularRange){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    int noOfDevice;
    cout<<"Enter number of device : ";
    cin>>noOfDevice;
    wirelessDevice* device[noOfDevice];
    float x,y,circularRange;
    int id;
    for(int i=0;i<noOfDevice;i++){
        cout<<"Enter details of wireless device "<<i+1<<" location as x y circularRange id : ";
        cin>>x>>y>>circularRange;
        cin>>id;
        device[i]=new wirelessDevice(x,y,id,circularRange);
    }
    cout<<"Now finding neighbour of each device \n";
    for(int i=0;i<noOfDevice;i++){
        for(int j=i+1;j<noOfDevice;j++){
            bool ans=device[i]->neighbour(*device[j]);
            if(ans){
                cout<<"The neighbour of id"<<device[i]->get_id()<<" device is device of id is "<<device[j]->get_id()<<endl;
            }
        }
    }
    cout<<"Now enter new location of every device : ";
    for(int i=0;i<noOfDevice;i++){
        
        cout<<"Enter new location of device id "<<device[i]->get_id()<<" : ";
        int newX,newY;
        cin>>newX>>newY;
        device[i]->setLocation(newX,newY);
        
    }
    cout<<"Now printing new neighbours of every location : "<<endl;
    for(int i=0;i<noOfDevice;i++){
        for(int j=i+1;j<noOfDevice;j++){
            bool ans=device[i]->neighbour(*device[j]);
            if(ans){
                cout<<"The new neighbour of id"<<device[i]->get_id()<<" device is device of id is "<<device[j]->get_id()<<endl;
            }
        }
    }
    return 0;
}