#include <iostream>

using namespace std;
int index_array[21]{};
string patient_name[21][5]{};
bool statics[21][5]{};
void delete_and_arrange(int specialization)
{
    for (int i = 0; i < index_array[specialization]; i++)
    {
        patient_name[specialization][i] = patient_name[specialization][i + 1];
        statics[specialization][i] = statics[specialization][i + 1];
    }
    index_array[specialization]--;
}
void add_new_patient_2(int specialization, string name, bool urgent)
{
    if (index_array[specialization] == 4)
    {
        cout << "sorry , we not have enough places ";
        return;
    }
    if (urgent)
    {
        index_array[specialization]++;
        for (int i = index_array[specialization] ; 0 < i; i--)
            patient_name[specialization][i] = patient_name[specialization][i - 1];
        patient_name[specialization][0] = name;
        statics[specialization][0] = true;

        return;
    }

    patient_name[specialization][index_array[specialization]] = name;
    index_array[specialization]++;
}
void add_new_patient()
{
    int specialization{};
    string name{};
    bool urgent{};
    cout << "enter specialization  please:\n ";
    cin >> specialization;
    cout << "enter your name  please:\n ";
    cin >> name;
    cout << "enter statics  please:\n ";
    cin >> urgent;
    add_new_patient_2(specialization, name, urgent);
}

void print_all_patients()
{
    for (int i = 1; i < 21; i++)
    {
        if (0 < index_array[i])
        {
            cout << "there are " << index_array[i] << " patients in specialization " << i << "" << endl;
            for (int j = 0; j < index_array[i]; j++)
            {

                cout << patient_name[i][j] << "  ";
                if (statics[i][j])
                {
                    cout << "urgent" << endl;
                    
                }
                else cout << "regular" << endl;
            }
        }
        
    }
}
void get_next_patient()
{
    int specialization{};
    cout << "Enter specialization:  ";
    cin >> specialization;
    if (0 < index_array[specialization])
    {
        cout << "  " << patient_name[specialization][0] << "  please go with the doctor \n";
        delete_and_arrange(specialization);
    }
    else
        cout << "no patient at the moment , have rest doctor\n ";
}
void hospital_system()
{
    int choice{};
    while (true)
    {

        cout << "Enter your choice: \n 1- add new patient\n 2- print all patients\n 3- get next patient\n 4- exit\n";

        cin >> choice;
        if (choice == 1)
            add_new_patient();
        if (choice == 2)
            print_all_patients();
        if (choice == 3)
            get_next_patient();
        if (choice == 4)
        {
            cout << "are you sure that you want to exit the system?\n"
                 << "please press 1 if you want to exit:\n";
            cin >> choice;
            if (choice == 1)
                return;
            else
            {
                choice = {};
                continue;
            }
        }
        if (!(1 <= choice && choice <= 4))
        {
            cout << " wrong input ,please try again\n";
            continue;
    }}
}

int main()
{
    hospital_system();
    return 0;
}
