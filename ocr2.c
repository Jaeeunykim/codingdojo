#include <stdio.h>

//c언어에서 boolean 타입 사용시 typedef로 선언해 주어야 함
typedef enum {false=0, true=1} bool;

/*typedef로 [4][3]짜리 2차원인 타입 만들기
c언어 배열 typdef하는 경우 순서 바뀜 typedef (type name) (사용할 명과 사이즈[][]);
기존 typedef (기존 타입) (사용할타입명);*/
typedef char OCRCELL [4][3];

void displayOCRCell(char c[4][9]);

bool isEqual(OCRCELL input, OCRCELL num);
OCRCELL cells[10] ={
    {
        {' ', '_', ' '},
        {'|', ' ', '|'},
        {'|', '_', '|'},
        {' ', ' ', ' '}
    },
    {
        {' ', ' ', ' '},
        {' ', ' ', '|'},
        {' ', ' ', '|'},
        {' ', ' ', ' '}
    },
    {
        {' ', '_', ' '},
        {' ', '_', '|'},
        {'|', '_', ' '},
        {' ', ' ', ' '}
    },
    {
        {' ', '_', ' '},
        {' ', '_', '|'},
        {' ', '_', '|'},
        {' ', ' ', ' '}
    },
    {
        {' ', ' ', ' '},
        {'|', '_', '|'},
        {' ', ' ', '|'},
        {' ', ' ', ' '}
    }, 
    {
        {' ', '_', ' '},
        {'|', '_', ' '},
        {' ', '_', '|'},
        {' ', ' ', ' '}
    },
    {
        {' ', '_', ' '},
        {'|', '_', ' '},
        {'|', '_', '|'},
        {' ', ' ', ' '}
    },
    {
        {' ', '_', ' '},
        {' ', ' ', '|'},
        {' ', ' ', '|'},
        {' ', ' ', ' '}
    },
    {
        {' ', '_', ' '},
        {'|', '_', '|'},
        {'|', '_', '|'},
        {' ', ' ', ' '}
    },
    {
        {' ', '_', ' '},
        {'|', '_', '|'},
        {' ', '_', '|'},
        {' ', ' ', ' '}
    }
};
void getNum(OCRCELL ocr);
bool isEqual(OCRCELL input, OCRCELL num);
void printNum(int *arr, int number);

int main(void){
    
    //input 2차원 배열 선언 
    char nums [4][9] = {
            {' ', '_', ' ', ' ', '_', ' ', ' ', '_', ' '},
            {'|', '_', '|', '|', '_', ' ', '|', '_', ' '},
            {'|', '_', '|', ' ', '_', '|', '|', '_', '|'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    displayOCRCell(nums);

    //쪼개기 
    int cell = sizeof(nums) / sizeof(OCRCELL);
    int numArr[cell];
    OCRCELL tempC;

    for(int count=0; count <9; count+=cell)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<3; j++)
            {
                tempC[i][j] = nums[i][j+count];
            }
        }
        
        getNum(tempC);
    }
    printf("\n");
}


void getNum(OCRCELL ocr){

    bool flag;

    for(int j=0; j<10; j++)
    {
        flag = isEqual(ocr, cells[j]);
        if(flag == true)
        {
            printf("%d ", j);
        }
    }
}

bool isEqual(OCRCELL input, OCRCELL num){

    for(int i =0; i<4; i++){
        for(int j =0; j<3; j++){
            if(input[i][j] != num[i][j]){
                return false;
            }
        }
    }
    return true;
};

//입력된 문자 출력 해주기
void displayOCRCell(char c[4][9])
{
    for(int i=0; i<4; i++){
        for (int j=0; j<9; j++){
            printf("%c", c[i][j]);
        }
        printf("\n");
    }
}

