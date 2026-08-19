// Last updated: 19/08/2026, 15:33:44
class Robot {
public:
    int x, y;
    int xmax, ymax;
    string dir;
    Robot(int width, int height) {
        x = 0;
        y = 0;
        xmax = width - 1;
        ymax = height - 1;
        dir = "E";
    }
    
    void step(int num) {
        int perimeter = 2 * (xmax + ymax);
    num %= perimeter;

    if(num == 0 && x == 0 && y == 0){
        dir = "S";
        return;
    }

    while(num--){
        if(dir == "E"){
            if(x + 1 <= xmax){
                x++;
            }else{
                dir = "N";
                y++;
            }
        }else if(dir == "N"){
            if(y + 1 <= ymax){
                y++;
            }else{
                dir = "W";
                x--;
            }
        }else if(dir == "W"){
            if(x - 1 >= 0){
                x--;
            }else{
                dir = "S";
                y--;
            }
        }else{
            if(y - 1 >= 0){
                y--;
            }else{
                dir = "E";
                x++;
            }
        }
    }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if(dir == "E")return "East";
        else if(dir == "S")return "South";
        else if(dir == "W")return "West";
        else return "North";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */