#include<iostream>
#include<cmath>
using namespace std;
class geometricalPoint{
	private:
		int x,y,z;
	public:
		geometricalPoint(int x,int y,int z){
			this->x=x;
			this->y=y;
			this->z=z;
		}
		void printDistance(geometricalPoint p1,geometricalPoint p2){
			cout<< sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
			cout<<endl;
		}

};

int main(){
	int x1,y1,z1,x2,y2,z2;
	cout<<"Enter two geometrical point in this format x y z : ";
	cin>>x1>>y1>>z1>>x2>>y2>>z2;
	geometricalPoint p1(x1,y1,z1) ,p2(x2,y2,z2);
	p1.printDistance(p1,p2);
	return 0;
}
