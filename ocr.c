#include <stdio.h>

//c언어에서 boolean 타입 사용시 typedef로 선언해 주어야 함
typedef enum {false=0, true=1} bool;

/*typedef로 [4][3]짜리 2차원인 타입 만들기
c언어 배열 typdef하는 경우 순서 바뀜 typedef (type name) (사용할 명과 사이즈[][]);
기존 typedef (기존 타입) (사용할타입명);*/
typedef char OCRCELL[4][3];

void displayOCRCell(OCRCELL c);

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

int main(void){
    
    //input 2차원 배열 선언 
    OCRCELL nums[] = {
        {
            {' ', '_', ' '},
            {'|', '_', '|'},
            {'|', '_', '|'},
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
        }
    };

    //input 갯수 count에 담기 
    int count = sizeof(nums)/(sizeof(OCRCELL));

    //input 문자 출력하기 
    for(int i=0; i<count; i++){
        displayOCRCell(nums[i]);
    }

    //isEqual함수를 이용해서 실제 숫자 확인 후 출력
    printf("input num is : ");
    for(int i =0; i<count; i++){
        for(int j=0; j<10; j++){
            int temp = isEqual(nums[i], cells[j]);
            if(temp == 1){
                printf("%d ", j);
            }
        }
    }
    printf("\n");
}

//input값과 숫자 비교하는 함수 
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
void displayOCRCell(OCRCELL c)
{
    for(int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            printf("%c", c[i][j]);
        }
        printf("\n");
    }
}
