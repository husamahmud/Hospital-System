#include "hospital_system.h"

/**
 * declares an array of deques where each deque can hold Patient object
 * and the size of the array is MAX_SPECIALIZATION constant
 */
deque<Patient> specializations[MAX_SPECIALIZATION];

/**
 * add_patient - add a new patient to the system
 */
void add_patient()
{
	string name;
	int spec;
	int stat;

	cout << "Enter specialization: ";
	cin >> spec;
	if (spec < 1 || spec > MAX_SPECIALIZATION)
	{
		cout << "Invalid specialization" << endl;
		return;
	}

	if (specializations[spec - 1].size() >= MAX_SPOTS)
	{
		cout << "Sorry, we can't add more patients for this specialization" << endl;
		return;
	}

	cout << "Enter patient's name: ";
	cin >> name;

	cout << "Enter patient's statue (0 for regular, 1 for urgent): ";
	cin >> stat;

	Patient patient;
	patient.name = name;
	patient.status = stat;

	if (stat)
		specializations[spec - 1].push_front(patient);
	else
		specializations[spec - 1].push_back(patient);
}

/**
 * print_patients - print all patients in the system
 */
void print_patients()
{
	int i;
	bool found = false;

	cout << "Specialization with waiting patients: " << endl;
	for (i = 0; i < MAX_SPECIALIZATION; i++)
	{
		if (!specializations[i].empty())
		{
			found = true;

			cout << "Specialization " << (i + 1) << ":" << endl;
			for (const auto &patient: specializations[i])
				cout << "Name: " << patient.name << ", Status: " << patient.status
				     << endl;
		}
	}

	if (!found)
		cout << "There is no waiting patients" << endl;
}

/**
 * get_next_patient - get the next patient for a given specialization
 */
void get_next_patient()
{
	int spec;

	cout << "Enter specialization: ";
	cin >> spec;
	if (spec < 1 || spec > MAX_SPECIALIZATION)
	{
		cout << "Invalid specialization" << endl;
		return;
	}

	if (specializations[spec - 1].empty())
	{
		cout << "No patients in this specialization" << endl;
		return;
	}


	Patient patient = specializations[spec - 1].front();
	specializations[spec - 1].pop_front();
	cout << "Doctor picked up patient (" << patient.name
	     << ") from specialization (" << spec << ")" << endl;
};

/**
 * menu - display the menu and get the user's choice
 */

int menu()
{
	int choice = -1;

	while (choice == -1)
	{
		cout << "###########################" << endl;
		cout << "Enter your choice: " << endl;
		cout << "1) Add new patient" << endl;
		cout << "2) Print all patient" << endl;
		cout << "3) Get next patient" << endl;
		cout << "4) Exit" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		if (!(choice >= 1 && choice <= 4))
		{
			cout << "Invalid choice. Try again" << endl;
			choice = -1;
		}
	}
	return (choice);
}

/**
 * Hospital_System_run - run the hospital system
 */
void Hospital_System_run()
{
	int choice;

	while (true)
	{
		choice = menu();

		if (choice == 1)
			add_patient();
		else if (choice == 2)
			print_patients();
		else if (choice == 3)
			get_next_patient();
		else
		{
			cout << "Exiting..." << endl;
			break;
		}
	}
}
