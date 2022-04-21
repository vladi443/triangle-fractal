/*
  Triangle Fractal is a c++ algorithm.
  This project is licensed under the GNU GPLv3 license, check github readme for more info.
  Check out other projects I am working on at vladi443.github.io/ziggurat
  Bugs and suggestions can be reported on the Wordle dictionary github repository.
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class point{
public:
    int value_id;
    int value_x;
    int value_y;
    char value_char;
};

void display_instructions();
void display_numberline();

int main(int argc, const char * argv[]) {
    srand(time(0));
    
    char grid[101][43];
    int iretation_count;
    vector<point> points_list;
    
    for (int y=0; y<43; y++){
        for (int x=0; x<101; x++){
            if (x==0||x==100){
                grid[x][y]='|';
            }else{
                grid[x][y]=' ';
            }
        }
    }
    
    display_instructions();
    
    cout<<"input number of future iretations: ";
    cin>>iretation_count;
    
    cout<<"simulating ..."<<endl<<endl;
    cout<<"[progress] ";
    
    int checkpoint=1000000;
    
    point init_point0;
    init_point0.value_id=0;
    init_point0.value_x=50;
    init_point0.value_y=0;
    init_point0.value_char='O';
    points_list.push_back(init_point0);
    
    point init_point1;
    init_point1.value_id=1;
    init_point1.value_x=1;
    init_point1.value_y=42;
    init_point1.value_char='O';
    points_list.push_back(init_point1);
    
    point init_point2;
    init_point2.value_id=2;
    init_point2.value_x=99;
    init_point2.value_y=42;
    init_point2.value_char='O';
    points_list.push_back(init_point2);
    
    int random_index1;
    int random_index2;
    bool unique_points=false;
    
    for (int tmp_counter=0; tmp_counter<iretation_count; tmp_counter++){
        if (tmp_counter>checkpoint){
            cout<<".";
            checkpoint=checkpoint+1000000;
        }
            while (!unique_points){
                random_index1=rand()%3;
                random_index2=rand()%points_list.size();
                if (random_index1!=random_index2){
                    unique_points=true;
                    break;
                }else{
                    unique_points=false;
                }
            }
            
            if (unique_points){
                point new_point;
                new_point.value_x=((points_list[random_index1].value_x)+(points_list[random_index2].value_x))/2;
                new_point.value_y=((points_list[random_index1].value_y)+(points_list[random_index2].value_y))/2;
                new_point.value_char='O';
                points_list.push_back(new_point);
                unique_points=false;
            }
    }
    
    cout<<" done"<<endl;
    display_numberline();
    
    for (int i=0; i<points_list.size(); i++){
        grid[points_list[i].value_x][points_list[i].value_y]=points_list[i].value_char;
    }
    
    for (int y=0; y<43; y++){
        for (int x=0; x<101; x++){
            cout<<grid[x][y];
        }
        cout<<endl;
    }
    cout<<endl<<"displaying sierpinski triangle after "<<iretation_count<<" future iretations"<<endl<<endl;
    
    cout<<"press enter to terminate session"<<endl;
    cin.ignore();
    
    return 0;
}

void display_instructions(){
    cout<<"# triangle fractal uses chaos game to simulate the sierpinski triangle after n-iretations"<<endl;
    cout<<"# chaos game refers to the random placement of the points"<<endl;
    cout<<"# algorithm picks a random number from the original triangle and a random number from within"<<endl;
    cout<<"# the triangle and places a new point mid distance between the two"<<endl;
    cout<<"# for more information regarding the sierpinski triangle check the ziggurat project site"<<endl<<endl;
    
    cout<<"# generated canvas size 99x43"<<endl;
    cout<<"# note: canvas size limits the amount of points that can be plotted"<<endl;
    cout<<"# note: realistically the pattern would be able to continue infinitely"<<endl;
    cout<<"# note: full screen terminal to display full canvas"<<endl<<endl;
}

void display_numberline(){
    cout<<"<";
    for (int i=0; i<100; i++){
        if (i>=10){
            if (i-(i/10)*10==0){
                cout<<"|";
            }else{
                cout<<i-(i/10)*10;
            }
        }else{
            if (i!=0){
                cout<<i;
            }
        }
    }
    cout<<">"<<endl;
}
