#include "Point2D.h"

using namespace std;

int compare_y_x(const void* a, const void* b)
{
    Point2D num1 = *(Point2D*)a;    // void 포인터를 Point2D 포인터로 변환한 뒤 역참조하여 값을 가져옴
    Point2D num2 = *(Point2D*)b;    // void 포인터를 Point2D 포인터로 변환한 뒤 역참조하여 값을 가져옴
    if (num1.get_y() < num2.get_y())    // a의 y좌표 < b의 y좌표
        return -1;      // -1 반환. -> qsort 함수에서 1,0,-1에 따라 정렬해줌
    if (num1.get_y() > num2.get_y())    // a의 y좌표 > b의 y좌표
        return 1;       // 1 반환. 

    // num1.ypos == num2.ypos 일경우

    if (num1.get_x() < num2.get_x())    // a의 x좌표 < b의 x좌표
        return -1;      // -1 반환.
    if (num1.get_x() > num2.get_x())    // a의 x좌표 > b의 x좌표
        return 1;       // 1 반환.
    
    return 0;    // a와 b가 완전히 같을경우 0 반환.
}