#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int pick;
    
    int bingo[5][5];
    int count[25] = {0};
    int number[5][5] = {0};
    srand(time(0));
    //產生bingo卡
    for (int i = 0; i <= 24; i ++){
        //選出數字 
        pick = rand() % 25;                
         //判斷重複       
        if (count[pick] == 0){            
            count[pick] ++;
            bingo[i/5][i%5] = pick;
        }
        else {
            i --;
        }
        
    }
    //輸出bingo卡
    for (int i = 0; i <= 4; i ++){        
        for (int j = 0; j <= 4; j ++){
            cout << bingo[i][j] + 1 << " ";
        }
        cout << endl;
    }


    //選出數字 
    pick = rand() % 25;  
    
    //判斷重複       
    if (count[pick] == 0){            
        count[pick] ++;
        cout << pick;
    }

    //標記抽中號碼
    for (int i = 0; i <=24; i ++){
        if (bingo[i/5][i%5] == pick){
            
        }
    }
}
