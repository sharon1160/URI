#include <iostream>
#include <math.h>
 
using namespace std;
 
int main() {
    int t,a,b,c;
    double cordX, cordY;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cordX = -((double)(b)/(double)(2*a));
        cordY = a*pow(cordX,2) + b*(cordX) + c;
        printf("%.2f\n", cordY);
    }
    return 0;
}
