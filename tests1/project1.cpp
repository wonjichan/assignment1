#include <iostream>

using namespace std;

void setPotion(int count, int* HP, int* p_Potion);
int main()
{
    int status[4] = {}; //[0]:HP [1]:MP [2]:att���ݷ� [3]:def���� 
    int* pst = status; //pst -> &status[0]
    
    cout << "HP�� MP�� �Է����ּ���: " << " ";
    while (status[0] <= 50 || status[1] <= 50)
    {
        cin >> *(pst);
        cin >> *(pst + 1);
        //cin >> status[0];//hp 
        //cin >> status[1];//mp 
        if (*(pst) <= 50 || *(pst + 1) <= 50)
        {
            cout << "HP�� MP�� �ٽ� �Է��ϼ���: " << " ";
        }
    }
    cout << "���ݷ°� ������ �Է��ϼ���: " << " ";
    while (*(pst + 2) <= 0 || *(pst + 3) <= 0)
    {
        cin >> *(pst + 2);
        cin >> *(pst + 3); 
        //cin >> status[2];
        //cin >> status[3]; 
        if (*(pst + 2) <= 0 || *(pst + 3) <= 0)
        {
            cout << "���ݷ°� ������ �ٽ� �Է��ϼ���: " << " ";
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
    cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� 5��)" << endl;
    cout << "=============================================" << endl;
    cout << "<���� ���� �ý���>" << endl;
    cout << "1.HP ȸ��\n2.MP ȸ��\n3.HP ��ȭ\n4.MP ��ȭ\n5.���� ��ų ���\n6.�ʻ�� ���\n7.������" << endl;
    while (true)
    {
        cout << "��ȣ�� �������ּ���: ";
        cin >> num;
        if (num == 1)
        {
            if (*p_Potion != 0)
            {
                cout << "HP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�." << endl;
                *(HP) += 20;
                *p_Potion -= 1;
                count = *p_Potion;
                cout << "���� HP: " << *HP << endl;
                cout << "���� ���� ��: " << count << endl;
            }
            else
            {
                cout << "������ �����մϴ�." << endl;
            }
        }
        else if (num == 2)
        {
            if (*(p_Potion+1) != 0)
            {
                cout << "MP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�." << endl;
                *(HP+1) += 20;
                *(p_Potion+1) -= 1;
                count = *(p_Potion+1);
                cout << "���� MP: " << *(HP+1) << endl;
                cout << "���� ���� ��: " << count << endl;
            }
            else
            {
                cout << "������ �����մϴ�." << endl;
            }
        }
        else if (num == 3)
        {
            cout << "HP�� 2�谡 �Ǿ����ϴ�." << endl; 
            *HP *= 2; 
            cout << "���� HP: " << *HP << endl;
        }
        else if (num == 4)
        {
            cout << "MP�� 2�谡 �Ǿ����ϴ�." << endl;
            *(HP+1) *= 2;
            cout << "���� HP: " << *(HP+1) << endl;
        }
        else if (num == 5)
        {
            if (*(HP + 1) >= 50)
            {
                cout << "* ��ų�� ����Ͽ� MP�� 50 �Ҹ�Ǿ����ϴ�." << endl; 
                *(HP + 1) -= 50; 
                cout << "���� MP: " << *(HP + 1) << endl;
            }
            else
            {
                cout << "��ų ����� �Ұ��մϴ�." << endl;
            }
        }
        else if (num == 6)
        {
            cout << "* ��ų�� ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�." << endl; 
            *(HP + 1) /= 2;
            cout << "���� MP: " << *(HP + 1) << endl;
        }
        else if (num == 7)
        {
            cout << "���α׷��� �����մϴ�." << endl; 
            break;
        }
    }
}