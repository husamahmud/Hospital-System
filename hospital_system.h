#ifndef HOSPITAL_SYSTEM_H
#define HOSPITAL_SYSTEM_H

#include <iostream>
#include <deque>
#include <string>

using namespace std;

/**
 * struct - a structure representing patient information
 * @name: the patient name
 * @status: the status of the patient
 */
struct Patient
{
	string name;
	int status{};
};

const int MAX_SPECIALIZATION = 20;
const int MAX_SPOTS = 5;

void add_patient();

void print_patients();

void get_next_patient();

int menu();

void Hospital_System_run();

#endif
