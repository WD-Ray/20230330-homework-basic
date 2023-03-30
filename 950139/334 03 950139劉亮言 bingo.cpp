#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int pick;
    
    int bingo[5][5];            //bingo卡
    int count[25] = {0};        //判別重複
    int number[5][5] = {0};     //標記抽中位置
    int cross, roll,  slash0, slash1 = 0;
    srand(time(0));
    //產生bingo卡
    for (int i = 0; i <= 24; i ++){
        //選出數字 
        pick = rand() % 25;                
         //判斷重複       
        if (count[pick] == 0){            
            count[pick] ++;
            bingo[i%5][i/5] = pick + 1;
        }
        else {
            i --;
        }
        
    }
    
    //輸出bingo卡
    for (int y = 0; y <= 4; y ++){        
        for (int x = 0; x <= 4; x ++){
            if(bingo[x][y] > 9){
                cout << bingo[x][y]  << " ";
            }
            else{
                cout << bingo[x][y]  << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "----------";
    cout << endl;

    for(int i = 0; i <=24; i ++){
        count[i] = 0;
    }
    
    for (int i  = 0; i <= 24; i ++){
        //選出數字 
        pick = rand() % 25;  
        
        //判斷重複       
        if (count[pick] == 0){            
            count[pick] ++;
            cout << pick + 1 << endl;
        }
        else{
            i --;
        }
    
        //標記抽中號碼
        for (int i = 0; i <=24; i ++){
            if (bingo[i%5][i/5] - 1 == pick){   
                number[i%5][i/5] ++;
                bingo[i%5][i/5] = 0;
                //輸出bingo卡
                for (int y = 0; y <= 4; y ++){        
                    for (int x = 0; x <= 4; x ++){
                        if(bingo[x][y] > 9){
                            cout << bingo[x][y]  << " ";
                        }
                        else{
                            cout << bingo[x][y]  << "  ";
                        }
                    }
                    cout << endl;
                }
                cout << endl;
                cout << "----------";
                cout << endl;
            }
            
        }
    
        //判斷橫排連線
        for (int y = 0; y <= 4; y ++){
            cross = 0;
            for (int x = 0; x <= 4; x++){
                if(number[x][y] > 0){
                    cross ++;
                }
                if (cross >= 5){
                    cout << "BINGO";
                    return 0;
                }
            }
        }

        //判斷直排連線
        for (int x = 0; x <= 4; x ++){
            roll = 0;
            for (int y = 0; y <= 4; y++){
                if(number[x][y] > 0){
                    roll ++;
                }
                if (roll >= 5){
                    cout << "BINGO";
                    return 0;
                }
            }
        }

        
        //判斷斜線連線
         slash0 = 0;
        for(int j = 0; j <= 4; j ++){
           
            if(number[j][j] > 0){
                    slash0 ++;
            }
            if (slash0 >= 5){
                cout << "BINGO";
                return 0;
            }
        }
        
        slash1 = 0;
        for(int j = 0; j <= 4; j ++){
            
            if(number[4-j][j] > 0){
                    slash1 ++;
            }
            if (slash1 >= 5){
                 cout << "BINGO";
                return 0;
            }
        }
    }
    
}

