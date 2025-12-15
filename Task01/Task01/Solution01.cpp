#include <iostream>
#include <cstdio> // printf 사용
using namespace std;

void addPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion += count;
    *p_MPPotion += count;
}

int main()
{
    const int SIZE = 5;
    int stat[SIZE] = { 0 }; // 0: HP, 1: MP, 2: Attack, 3: Defense, 4: Level

    stat[4] = 1;

    while (1)
    {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> stat[0] >> stat[1];

        if (stat[0] > 50 && stat[1] > 50)
        {
            break;
        }
        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
    }

    while (1)
    {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> stat[2] >> stat[3];

        if (stat[2] > 0 && stat[3] > 0)
        {
            break;
        }
        cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요.\n";
    }

    int choice = 0;
    int HPPotion = 0;
    int MPPotion = 0;

    addPotion(5, &HPPotion, &MPPotion);

    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";
    cout << "=============================================\n";
    cout << "<스탯 관리 시스템>\n1. HP UP\n2. MP UP\n3. 공격력 UP\n4. 방어력 UP\n5. 현재 능력치\n6. Level UP\n0. 나가기\n";

    while (true)
    {
        cout << "\n번호를 선택해주세요 : ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "프로그램을 종료합니다\n";
            break;
        }

        switch (choice)
        {
        case 1:
            if (HPPotion > 0)
            {
                stat[0] += 20;
                HPPotion--;
                printf("* HP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n현재 HP: %d\n남은 포션 수: %d\n", stat[0], HPPotion);
            }
            else
            {
                cout << "포션이 부족합니다\n";
            }
            break;
        case 2:
            if (MPPotion > 0)
            {
                stat[1] += 20;
                MPPotion--;
                printf("* MP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n현재 MP: %d\n남은 포션 수: %d\n", stat[1], MPPotion);
            }
            else
            {
                cout << "포션이 부족합니다\n";
            }
            break;
        case 3:
            stat[2] *= 2;
            printf("* 공격력이 2배로 증가되었습니다.\n현재 공격력 : %d\n", stat[2]);
            break;
        case 4:
            stat[3] *= 2;
            printf("* 방어력이 2배로 증가되었습니다.\n현재 방어력 : %d\n", stat[3]);
            break;
        case 5:
            printf("* 레벨 : %d, HP : %d, MP : %d, 공격력 : %d, 방어력 : %d, 남은 HP/MP 포션 수 : %d/%d\n", stat[4], stat[0], stat[1], stat[2], stat[3], HPPotion, MPPotion);
            break;
        case 6:
            cout << "* 레벨업! HP/MP 포션이 지급됩니다.\n";
            addPotion(1, &HPPotion, &MPPotion);
            stat[4]++;
            printf("남은 HP/MP 포션 수 : %d/%d\n", HPPotion, MPPotion);
            break;
        default:
            cout << "정확한 번호를 입력해주세요.\n";
            break;
        }
    }
    return 0;
}