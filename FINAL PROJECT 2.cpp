#include <iostream>
#include <string>

using namespace std;

int listNumber = 5;

void top_display() {
	cout << "\n======================================================\n";
	cout << "                   TO DO LIST                           \n";
	cout << "\n======================================================\n";
} 
void bottom_display() {
	cout << "\n======================================================\n";
	cout << "                                                        \n";
	cout << "\n======================================================\n";
}
int main () {
	string to_do[listNumber];
	int task_number = 0;
	
	int choice;
	do {
		top_display();
		cout << "\n1. Add a new task" << endl;
		cout << "2. View all tasks" << endl;
		cout << "3. Update a task" << endl;
		cout << "4. Delete a task" << endl;
		cout << "5. Exit" << endl;
		cout << "\nChoose an option: ";
		cin >> choice;
		cout << "\n------------------------------------------\n";
		
		int create_task(string to_do[], int task_number);
        void  read_task(string to_do[], int task_number);
        int update_task(string to_do[], int task_number);
        int delete_task(string to_do[], int task_number);
        
		switch (choice) 
		{
			case 1:
				task_number = create_task(to_do, task_number);
				break;
			case 2:
				read_task(to_do, task_number);
				break;
			case 3:
				task_number = update_task(to_do, task_number);
				break;
			case 4:
				task_number = delete_task(to_do, task_number);
				break;
			case 5:
				cout << "Exiting!" << endl;
				bottom_display();
				break;
			default:
				cout << "Invalid choice, Please try again.\n" << endl;
		}
	} 
	while (choice != 5);
	return 0;
}

int create_task(string to_do[], int task_number) 
{
    if (task_number < listNumber) {
        cout << "\nEnter a new task: ";
        cin.ignore();
        getline(cin, to_do[task_number]);  
        task_number++;
        
        cout << "\nNew task added!\n" << endl;
        
    } else {
        cout << "\nTask list is full!\n" << endl;
    }
    return task_number;
}

void read_task(string to_do[], int task_number) 
{
    if (task_number == 0) {
        cout << "\nNo task to display.\n" << endl;
        
    } else {
        cout << "\nTo do List: \n" << endl;
        
        for (int i = 0; i < task_number; i++) {
            cout << i + 1 << ". " << to_do[i] << endl;
        }
        cout << "\n------------------------------------------\n";
    }
}

int update_task(string to_do[], int task_number) 
{
    int index;
    cout << "Enter a task number to replace: ";
    cin >> index;

    if (index >= 1 && index <= task_number) {
        cout << "Enter new task: ";
        cin.ignore();
        getline(cin, to_do[index - 1]);
		 
        cout << "\nNew task updated!\n" << endl;
        
    } else {
        cout << "\nInvalid task number!\n" << endl;
    }
    return task_number;
}

int delete_task(string to_do[], int task_number) {
	
    int index;
    cout << "Enter a task number to delete: ";
    cin >> index;

    if (index >= 1 && index <= task_number) {
        for (int i = index - 1; i < task_number - 1; i++) 
		{
            to_do[i] = to_do[i + 1];  
        }
        task_number--;
        cout << "\nTask has been removed!\n" << endl;
        
    } else {
        cout << "\nInvalid task number!\n" << endl;
    }
    return task_number;
}


