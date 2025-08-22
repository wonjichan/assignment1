#include <iostream>

using namespace std;

void setPotion(int count, int* HP, int* p_Potion);
int main()
{
    int status[4] = {}; //[0]:HP [1]:MP [2]:att공격력 [3]:def방어력 
    int* pst = status; //pst -> &status[0]
    
    cout << "HP와 MP를 입력해주세요: " << " ";
    while (status[0] <= 50 || status[1] <= 50)
    {
        cin >> *(pst);
        cin >> *(pst + 1);
        //cin >> status[0];//hp 
        //cin >> status[1];//mp 
        if (*(pst) <= 50 || *(pst + 1) <= 50)
        {
            cout << "HP와 MP를 다시 입력하세요: " << " ";
        }
    }
    cout << "공격력과 방어력을 입력하세요: " << " ";
    while (*(pst + 2) <= 0 || *(pst + 3) <= 0)
    {
        cin >> *(pst + 2);
        cin >> *(pst + 3); 
        //cin >> status[2];
        //cin >> status[3]; 
        if (*(pst + 2) <= 0 || *(pst + 3) <= 0)
        {
            cout << "공격력과 방어력을 다시 입력하세요: " << " ";
        }
    }
    int count = 0;
    int potion[2] = { 5,5 }; 
    setPotion(count, pst, potion);
    return 0; 
}
void setPotion(int count, int* HP, int* p_Potion)
{
    int num = 0;
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
    cout << "=============================================" << endl;
    cout << "<스탯 관리 시스템>" << endl;
    cout << "1.HP 회복\n2.MP 회복\n3.HP 강화\n4.MP 강화\n5.공격 스킬 사용\n6.필살기 사용\n7.나가기" << endl;
    while (true)
    {
        cout << "번호를 선택해주세요: ";
        cin >> num;
        if (num == 1)
        {
            if (*p_Potion != 0)
            {
                cout << "HP가 20 회복되었습니다. 포션이 1개 차감됩니다." << endl;
                *(HP) += 20;
                *p_Potion -= 1;
                count = *p_Potion;
                cout << "현재 HP: " << *HP << endl;
                cout << "남은 포션 수: " << count << endl;
            }
            else
            {
                cout << "포션이 부족합니다." << endl;
            }
        }
        else if (num == 2)
        {
            if (*(p_Potion+1) != 0)
            {
                cout << "MP가 20 회복되었습니다. 포션이 1개 차감됩니다." << endl;
                *(HP+1) += 20;
                *(p_Potion+1) -= 1;
                count = *(p_Potion+1);
                cout << "현재 MP: " << *(HP+1) << endl;
                cout << "남은 포션 수: " << count << endl;
            }
            else
            {
                cout << "포션이 부족합니다." << endl;
            }
        }
        else if (num == 3)
        {
            cout << "HP가 2배가 되었습니다." << endl; 
            *HP *= 2; 
            cout << "현재 HP: " << *HP << endl;
        }
        else if (num == 4)
        {
            cout << "MP가 2배가 되었습니다." << endl;
            *(HP+1) *= 2;
            cout << "현재 HP: " << *(HP+1) << endl;
        }
        else if (num == 5)
        {
            if (*(HP + 1) >= 50)
            {
                cout << "* 스킬을 사용하여 MP가 50 소모되었습니다." << endl; 
                *(HP + 1) -= 50; 
                cout << "현재 MP: " << *(HP + 1) << endl;
            }
            else
            {
                cout << "스킬 사용이 불가합니다." << endl;
            }
        }
        else if (num == 6)
        {
            cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다." << endl; 
            *(HP + 1) /= 2;
            cout << "현재 MP: " << *(HP + 1) << endl;
        }
        else if (num == 7)
        {
            cout << "프로그램을 종료합니다." << endl; 
            break;
        }
    }
}