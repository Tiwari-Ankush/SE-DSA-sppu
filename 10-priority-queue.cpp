/*
Consider a scenario for Hospital to cater services to different kinds of patients as Serious
(top priority), b) non-serious (medium priority), c) General Checkup (Least priority).
Implement the priority queue to cater services to the patients.

*/
#include <iostream>

#define N 20

#define SERIOUS 10
#define NONSERIOUS 5
#define CHECKUP 1

using namespace std;

string Q[N];
int Pr[N];
int r = -1, f = -1;

void enqueue(string data, int p) // Enqueue function to insert data and its priority in queue
{
	int i;
	if ((f == 0) && (r == N - 1)) // Check if Queue is full
		cout << "Queue is full";
	else
	{
		if (f == -1)
		{ // if Queue is empty
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;
		}
		else if (r == N - 1)
		{ // if there there is some elemets in Queue
			for (i = f; i <= r; i++)
			{
				Q[i - f] = Q[i];
				Pr[i - f] = Pr[i];
				r = r - f;
				f = 0;
				for (i = r; i > f; i--)
				{
					if (p > Pr[i])
					{
						Q[i + 1] = Q[i];
						Pr[i + 1] = Pr[i];
					}
					else
						break;

					Q[i + 1] = data;
					Pr[i + 1] = p;
					r++;
				}
			}
		}
		else
		{
			for (i = r; i >= f; i--)
			{
				if (p > Pr[i])
				{
					Q[i + 1] = Q[i];
					Pr[i + 1] = Pr[i];
				}
				else
					break;
			}
			Q[i + 1] = data;
			Pr[i + 1] = p;
			r++;
		}
	}
}

void print()
{ // print the data of Queue
	int i;
	if (f == -1)
	{
		cout << "No records found\n";
		return;
	}

	for (i = f; i <= r; i++)
	{
		cout << "Patient's Name - " << Q[i];
		switch (Pr[i])
		{
		case 1:
			cout << " Priority - 'Checkup' " << endl;
			break;
		case 5:
			cout << " Priority - 'Non-serious' " << endl;
			break;
		case 10:
			cout << " Priority - 'Serious' " << endl;
			break;
		default:
			cout << "Priority not found" << endl;
		}
	}
}

void dequeue()
{ // remove the data from front
	if (f == -1)
	{
		cout << "Queue is Empty";
	}
	else
	{
		cout << "deleted Element =" << Q[f] << endl;
		cout << "Its Priority = " << Pr[f] << endl;
		if (f == r)
			f = r = -1;
		else
			f++;
	}
}

int main()
{

	string data;
	int opt = 0, p;

	while (opt != 4)
	{
		cout << "PRIORITY QUEUE \n";
		cout << "1. Insert data\n2. Display data\n3. Delete data\n4. Exit\n";
		cout << "Enter your choice: ";
		cin >> opt;

		switch (opt)
		{
		case 1:
			cout << "Enter patient name: ";
			cin >> data;
			cout << "Enter priority of patient(1 - Serious, 2 - Non-serious, 3 - General checkup): ";
			cin >> p;

			switch (p)
			{
			case 1:
				enqueue(data, SERIOUS);
				break;

			case 2:
				enqueue(data, NONSERIOUS);
				break;

			case 3:
				enqueue(data, CHECKUP);
				break;

			default:
				cout << "Enter valid priority value!\n";
				break;
			}

			break;

		case 2:
			print();
			break;

		case 3:
			dequeue();
			break;

		case 4:
			break;

		default:
			cout << "Enter valid option!\n";
			break;
		}
	}

	return 0;
}
