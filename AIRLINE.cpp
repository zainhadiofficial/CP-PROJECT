#include<iostream>
#include <iomanip>
#include <random>
#include<windows.h>
#include<string.h>
#include<string>
#include <ctime>
#include<cstdlib>
#include<fstream>
#include<conio.h>
using namespace std;
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";

struct pasdetails {
		string passengerfirstname[10];
		string passengerlastname[10];
		int passengerage[10];
		string gender[10];
		string passengerid[10];
		string phonenumber[10];
		string emailid[10];
		string address[10];
	}passdett;
	
	int choice;

	struct flightinfoncharges {
		float charges[10];
		string flightN[6];
		int flightid[10];
		string flighttype[10];
	}fnit;
	
	struct ticket_details {
		int ticketIDs[10]; // Store ticket IDs
		double ticketPrices[10]; // Store ticket prices
	}ticdet;
	
	struct luggage_details {
		int no_ofluggages;
		int luggageid[10][10];
		float luggageweight[10];
	}lugdet;

	struct logdetails {
		string loginid,id;
		string loginpassword,pass;
	}logdet;
	void login()
	{
		int chances = 0;
		string key1;
	redo:
		cout << "" << endl << endl;
		cout << GREEN << "\n\n\t\t\t\t\t\t\t     WELCOME TO ISLAMABAD AIRLINES\n" << RESET <<endl;
		cout<< endl<< GREEN<< "\t\t\t\t\t\t\t\t ENTER THE LOGIN ID: " << RESET;
		if (chances == 0) {
			cout << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t      ";
		}
		cin >> logdet.loginid;
		cout << GREEN << "\n\t\t\t\t\t\t\t\t ENTER THE LOGIN PASSWORD: " << RESET;
		cin >> logdet.loginpassword;
		ifstream readid("id.txt", ios::in);
		getline(readid,logdet.id);
		readid.close();
		ifstream readpass("pass.txt", ios::in);
		getline(readpass, logdet.pass);
		readpass.close();
		if (logdet.loginid != logdet.id || logdet.loginpassword != logdet.pass)
		{
			cout << RED << "\t\t\t\t\t\t\t\t WRONG LOGIN ID OR LOGIN PASSWORD ENTERED!!!" << RESET << endl;
			chances++;
			if (chances == 3) {
				cout << RED << "\t\t\t\t\t\t\t\t LOGIN DETAILS ENTRY LIMIT REACHED!!! PLEASE TRY AGAIN LATER!!!" << RESET << endl;
				exit(0);
			}
			cout << RED << "\t\t\t\t\t\t\t\t PRESS ANY KEY AND ENTER TO LOGIN AGAIN " << RESET;
			cin >> key1;
			system("cls");
			goto redo;
		}
		cout << GREEN << "\n\n\t\t\t\t\t\t\t\t AUTHORIZATION SUCCESSFULL!!\n" << RESET << endl;
	}

	void writeairdetails() {
		ofstream outFile("Airline management proj.txt", ios::app);
		outFile << "\n\t__________Islamabad Airlines____________ \n" << endl;
		outFile << "\t______________Main Menu_________________" << endl;
		outFile << "\t________________________________________" << endl;

	}

	void putdetails(int i)
	{
		cout << CYAN << "\n\t\t\t\t\t\t\t\t Please Enter valid details below: " << RESET;
		cout << YELLOW << "\n\t\t\t\t\t\t\t\t Details for " << " Passenger " << i + 1 << ". | " << RESET;
		cout << GREEN << "\n\t\t\t\t\t\t\t\t First Name: " << RESET;
		cin >> passdett.passengerfirstname[i];
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Last name: " << RESET;
		cin >> passdett.passengerlastname[i];
		reentergender:
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Gender(Male/Female): " << RESET;
		cin >> passdett.gender[i];
		if (passdett.gender[i] != "male" || passdett.gender[i] != "Male" || passdett.gender[i] != "MALE" || passdett.gender[i] != "female" || passdett.gender[i] != "Female" || passdett.gender[i] != "FEMALE") {
			cout << RED << "\n\t\t\t\t\t\t\t\t PLEASE ENTER VALID GENDER!!!" << RESET << endl;
			goto reentergender;
		}
	re_enterage:
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Age (1-80): " << RESET;
		cin >> passdett.passengerage[i];
		if (passdett.passengerage[i] < 1 || passdett.passengerage[i]>80)
		{
			cout << RED << "\n\t\t\t\t\t\t\t\t PLEASE ENTER VALID AGE!!!" << RESET << endl;
			goto re_enterage;
		}
	re_enterid:
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Passenger CNIC (Without Dashes) : " << RESET;
		cin >> passdett.passengerid[i];
		if (!(passdett.passengerid[i].length() == 13)) {
			cout << RED << "\n\t\t\t\t\t\t\t\t INCORRECT ID AND ITS FORMAT!!!" << RESET << endl;
			cout << RED << "\n\t\t\t\t\t\t\t\t PLEASE RE-ENTER VALID ID!!!" << RESET << endl;
			goto re_enterid;
		}
	re_enternumber:
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Phone number: " << RESET;
		cin >> passdett.phonenumber[i];
		if (!(passdett.phonenumber[i].length() == 11)) {
			cout << RED << "\n\t\t\t\t\t\t\t\t INCORRECT NUMBER AND ITS FORMAT!!!" << RESET << endl;
			cout << RED << "\n\t\t\t\t\t\t\t\t PLEASE RE-ENTER VALID NUMBER!!!" << RESET << endl;
			goto re_enternumber;
		}
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Email ID (........@gmail.com) : " << RESET;
		cin >> passdett.emailid[i];
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Address: " << RESET;
		cin >> passdett.address[i];

	}

	void displaypassengerdetails(int i)
	{

		cout << CYAN << "\n\t\t\t\t\t\t\t\t PASSENGERS DETAILS: " << RESET;
		cout << GREEN << "\n\t\t\t\t\t\t\t\t First Name: " << RESET << passdett.passengerfirstname[i];
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Last Name: " << RESET << passdett.passengerlastname[i];
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Gender: " << RESET << passdett.gender[i];

		if (passdett.passengerage[i] > 0 && passdett.passengerage[i] < 95)
		{
			cout << GREEN << "\n\t\t\t\t\t\t\t\t Age: " << RESET << passdett.passengerage[i];
		}
		else
		{
			cout << RED << "\n\t\t\t\t\t\t\t\t Invalid age" << RESET;
		}
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Passenger ID (without dashes): " << RESET;
		if (passdett.passengerid[i].length() == 13)
		{
			cout << passdett.passengerid[i];
		}
		else
		{
			cout << RED << "\n\t\t\t\t\t\t\t\t Invalid Entry!" << RESET;
		}
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Phone number: " << RESET;
		if (passdett.phonenumber[i].length() == 11)
		{
			cout << passdett.phonenumber[i];
		}
		else
		{
			cout << RED << "\n\t\t\t\t\t\t\t\t Invalid Entry!" << RESET;
		}
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Email: " << RESET << passdett.emailid[i] << "@gmail.com";
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Address: " << RESET << passdett.address[i];

	}
	void writepastofile(ofstream& file, int i)
	{
		ofstream outFile("Airline management proj.txt", ios::app);

		if ((passdett.passengerage[i] > 0 && passdett.passengerage[i] < 95) && (passdett.passengerid[i].length() == 13) && (passdett.phonenumber[i].length() == 11))
		{
			outFile << "\n First Name " << passdett.passengerfirstname[i];
			outFile << "\nLast Name " << passdett.passengerlastname[i];
			outFile << "\n AGE  ";
			outFile << passdett.passengerage[i];

			outFile << "\n Gender " << passdett.gender[i];
			outFile << "\nCNIC  " << passdett.passengerid[i];
			outFile << "\nPhone Number " << passdett.phonenumber[i];
			outFile << "\nEmail: " << passdett.emailid[i] << "@gmail.com";
			outFile << "\nAddress: " << passdett.address[i];
		}
		else
		{
			outFile << "\n\t\tInvalid Entry!";
			exit(0);
		}

	}
	string flightN[6] = { "Lahore", "Karachi", "Peshawar", "Multan", "Quetta", "Skardu" };
	void flights(int i)
	{
		cout << CYAN << "\n\n\t\t\t\t\t\t\t\t FLIGHT DESTINATIONS:" << RESET;
		for (int a = 0; a < 6; a++)
		{
			cout << GREEN << " \n\t\t\t\t\t\t\t\t " << (a + 1) << " Flight to " << flightN[a] << RESET << endl;
		}

		cout << CYAN << "\n\n\t\t\t\t\t\t\t\t FLIGHT DETAILS: " << RESET;
		cout << GREEN << "\n\t\t\t\t\t\t\t\t Welcome to the Islamabad Airlines!" << RESET << endl;

		cout << YELLOW << "\n\t\t\t\t\t\t\t\t Press the number of the city of which you want to book the flight: " << RESET;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << GREEN << "\t\t\t\t\t\t\t\t __" << flightN[choice - 1] << "_\n" << RESET;       //choice - 1 is done to get the index number of array 
			cout << GREEN << "\t\t\t\t\t\t\t\t| Your comfort is our priority. Enjoy the journey! |" << RESET << endl;
			fnit.charges[i] = 14000;
			fnit.flightid[i] = rand();
			cout << CYAN << "\n\t\t\t\t\t\t\t\t| Flight ID: " << fnit.flightid[i] << RESET;
			cout << GREEN << "\n\t\t\t\t\t\t\t\t| You have successfully booked the flight to Lahore |" << RESET << endl;
			break;
		}
		case 2:
		{
			cout << GREEN << "\t\t\t\t\t\t\t\t| __" << flightN[choice - 1] << "_\n" << RESET;
			cout << GREEN << "\t\t\t\t\t\t\t\t| Your comfort is our priority. Enjoy the journey! |" << RESET << endl;
			fnit.charges[i] = 20000;
			fnit.flightid[i] = rand();
			cout << CYAN << "\n\t\t\t\t\t\t\t\t| Flight ID: " << fnit.flightid[i] << RESET;
			cout << GREEN << "\n\t\t\t\t\t\t\t\t| You have successfully booked the flight to Karachi |" << RESET << endl;
			break;
		}
		case 3:
		{
			cout << GREEN << "\t\t\t\t\t\t\t\t| __" << flightN[choice - 1] << "_\n" << RESET;
			cout << GREEN << "\t\t\t\t\t\t\t\t| Your comfort is our priority. Enjoy the journey! |" << RESET << endl;
			fnit.charges[i] = 15500;
			fnit.flightid[i] = rand();
			cout << CYAN << "\n\t\t\t\t\t\t\t\t| Flight ID: " << fnit.flightid[i] << RESET;
			cout << GREEN << "\n\t\t\t\t\t\t\t\t| You have successfully booked the flight to Peshawar |" << RESET << endl;
			break;
		}
		case 4:
		{
			cout << GREEN << "\t\t\t\t\t\t\t\t| __" << flightN[choice - 1] << "_\n" << RESET;
			cout << GREEN << "\t\t\t\t\t\t\t\t| Your comfort is our priority. Enjoy the journey! |" << RESET << endl;
			fnit.charges[i] = 12000;
			fnit.flightid[i] = rand();
			cout << CYAN << "\n\t\t\t\t\t\t\t\t| Flight ID: " << fnit.flightid[i] << RESET;
			cout << GREEN << "\n\t\t\t\t\t\t\t\t| You have successfully booked the flight to Multan |" << RESET << endl;
			break;
		}
		case 5:
		{
			cout << GREEN << "\t\t\t\t\t\t\t\t| __" << flightN[choice - 1] << "_\n" << RESET;
			cout << GREEN << "\t\t\t\t\t\t\t\t| Your comfort is our priority. Enjoy the journey! |" << RESET << endl;
			fnit.charges[i] = 15000;
			fnit.flightid[i] = rand();
			cout << CYAN << "\n\t\t\t\t\t\t\t\t| Flight ID: " << fnit.flightid[i] << RESET;
			cout << GREEN << "\n\t\t\t\t\t\t\t\t| You have successfully booked the flight to Quetta |" << RESET << endl;
			break;
		}
		case 6:
		{
			cout << GREEN << "\t\t\t\t\t\t\t\t| __" << flightN[choice - 1] << "_\n" << RESET;
			cout << GREEN << "\t\t\t\t\t\t\t\t| Your comfort is our priority. Enjoy the journey! |" << RESET << endl;
			fnit.charges[i] = 17000;
			fnit.flightid[i] = rand();
			cout << CYAN << "\n\t\t\t\t\t\t\t\t| Flight ID: " << fnit.flightid[i] << RESET;
			cout << GREEN << "\n\t\t\t\t\t\t\t\t| You have successfully booked the flight to Skardu |" << RESET << endl;
			break;
		}
		default:
		{
			cout << RED << "\t\t\t\t\t\t\t\t| Invalid input! |" << RESET << endl;
			break;
		}
		}
	}
	void writeflighttofile(ofstream& file, int i)
	{
		ofstream outFile("Airline management proj.txt", ios::app);
		outFile << "\nFlight ID " << fnit.flightid[i] << endl;

	}
	double calculateTicketPrice(int a)
	{
		double basePrice = fnit.charges[a] / 150.0;
		double priceMultiplier = (fnit.flighttype[a] == "business" || fnit.flighttype[a] == "Business") ? 1.5 : 1.0;
		double destinationMultiplier = 1.2;
		return basePrice * priceMultiplier * destinationMultiplier;
	}

	void addtickets(int i)
	{

		cout << YELLOW << "\n\t\t\t\t\t\t\t\t Enter your Flight type (Business or Economy):" << RESET;
		cin >> fnit.flighttype[i];
		ticdet.ticketIDs[i] = rand(); // Generate a random ticket ID
		ticdet.ticketPrices[i] = calculateTicketPrice(i);

	}

	tm generateRandomDate() {

		tm randomDate = { 0 };
		// Set the year
		randomDate.tm_year = 124; // 2024 - 1900

		// Set the month (July or August)
		randomDate.tm_mon = rand() % 2 + 6; // 6 for July, 7 for August

		// Set the day (1 to 31)
		randomDate.tm_mday = rand() % 31 + 1;

		return randomDate;
	}
	void displaytickets(int i,string s)
	{

		tm randomDate = generateRandomDate();
		cout << GREEN << "\n\t\t\t\t\t\t\t\t TICKET PRICE: $" << ticdet.ticketPrices[i] << endl<<endl << RESET;

		// Width of the ticket
		int width = 70;

		// Top border
		cout <<CYAN << "\t\t\t\t\t\t\t"  << setfill('=') << setw(width) << "=" << endl;
		cout  << setfill(' '); // reset fill character

		// Header
		cout << CYAN << "\t\t\t\t\t\t\t" << setw((width - 12) / 2) << "" << "BOARDING TICKET"  << endl;
		cout << CYAN << "\t\t\t\t\t\t\t" << setfill('=') << setw(width) << "=" << endl;
		cout  << setfill(' '); // reset fill character

		// Left section details
		cout << CYAN << "\t\t\t\t\t\t\t" << setw(12) << left << "PASSENGER" << ": " << passdett.passengerfirstname[i]<<" "<< passdett.passengerlastname[i] << endl;
		cout << CYAN << "\t\t\t\t\t\t\t" << setw(12) << left << "TICKET ID" << ": " << ticdet.ticketIDs[i] << endl;
		cout << CYAN << "\t\t\t\t\t\t\t" << setw(12) << left << "FLIGHT ID" << ": " << fnit.flightid[i] << endl;


		// Right section details
		cout << CYAN << "\t\t\t\t\t\t\t" << setw(15) << left << "DESTINATION" << ": " << "Islamabad" << " ---> " << flightN[choice - 1] << endl;
		cout << CYAN << "\t\t\t\t\t\t\t" << setw(15) << left << "SEAT" << ": " << s  << endl;
		cout << CYAN << "\t\t\t\t\t\t\t" << setw(15) << left << "DATE" << ": " <<  randomDate.tm_year + 1900 << "-" << randomDate.tm_mon + 1 << "-" << randomDate.tm_mday << endl;
		if (choice == 1) {
			cout << CYAN << "\t\t\t\t\t\t\t" << setw(15) << "Departure Time : 09 : 30 AM        Arrival Time : 10 : 30 AM " << RESET;
		}
		else if (choice == 2) {
			cout << CYAN << "\t\t\t\t\t\t\t" << setw(15) << "Departure Time : 10 : 45 AM        Arrival Time : 12 : 30 PM " << RESET;
		}
		else if (choice == 3) {
			cout << CYAN << "\t\t\t\t\t\t\t" << setw(15) << "Departure Time : 01 : 00 PM        Arrival Time : 01 : 45 PM " << RESET;
		}
		else if (choice == 4) {
			cout << CYAN << "\t\t\t\t\t\t\t" << setw(15) << "Departure Time : 02 : 00 PM        Arrival Time : 03 : 00 PM " << RESET;
		}
		else if (choice == 5) {
			cout << CYAN << "\t\t\t\t\t\t\t" << setw(15) << "Departure Time : 03 : 20 PM        Arrival Time : 04 : 20 PM " << RESET;
		}
		else if (choice == 6) {
			cout << CYAN << "\t\t\t\t\t\t\t" << setw(15) << "Departure Time : 04 : 30 PM        Arrival Time : 05 : 30 PM " << RESET;
		}
		// Bottom border
		cout << CYAN << "\n\t\t\t\t\t\t\t" << setfill('=') << setw(width) << "=" <<RESET<< endl;


	}

	void writeticktofile(ofstream& file, int i)
	{
		ofstream outFile("Airline management proj.txt", ios::app);
		outFile << "\n Flight Type" << fnit.flighttype[i] << "\n Ticket ID " << ticdet.ticketIDs[i] << "\n Ticket Price $" << ticdet.ticketPrices[i] << endl;
		outFile.close();
	}
	char choose;
	float extraluggageprice = 0;

	void luggagedetails(int i)
	{
		cout << CYAN << "\n\n\t\t\t\t\t\t\t\t Enter Number of Luggages: " << RESET;
		cin >> lugdet.no_ofluggages;
		cout << CYAN << "\n\t\t\t\t\t\t\t\t Luggage Details:" << RESET;
		cout << YELLOW << "\n\t\t\t\t\t\t\t\t Number of luggages: " << lugdet.no_ofluggages << RESET;

		for (int j = 0; j < lugdet.no_ofluggages; j++)
		{
			lugdet.luggageid[i][j] = rand();
			cout << GREEN << "\n\t\t\t\t\t\t\t\t Luggage " << j + 1 << " ID: " << lugdet.luggageid[i][j] << RESET;
			cout << GREEN << "\n\n\t\t\t\t\t\t\t\t Enter Luggage weight of " << j + 1 << " luggage in kg: " << RESET;
		xyz:
			cin >> lugdet.luggageweight[j];
			if (lugdet.luggageweight[j] > 32) {
				cout << RED << "\n\n\t\t\t\t\t\t\t\t Luggage weight exceeding the weight limit!!! " << RESET << endl;
				cout << RED << "\n\n\n\t\t\t Would you like to pay for extra luggage or reduce the weight? Press Y to pay extra charges or press N to reduce weight! " << RESET;
				cin >> choose;
				if (choose == 'y' || choose == 'Y') {
					extraluggageprice = extraluggageprice + (lugdet.luggageweight[j] - 32) * 1.5;
				}
				else {
					cout << GREEN << "\n\n\t\t\t\t\t\t\t\t Enter the reduced Luggage weight again: " << RESET;
					goto xyz;
				}
			}
		}
		cout << GREEN << "\n\n\t\t\t\t\t\t\t\tLuggage weight price to be paid is: " << extraluggageprice << "$" << RESET << endl;

	}

	void writelugtofile(ofstream& file, int i)
	{
		ofstream outFile("Airline management proj.txt", ios::app);
		for (int j = 0; j < lugdet.no_ofluggages; j++) {
			outFile << "\nluggage ID " << j + 1 << " " << lugdet.luggageid[i][j] << endl;
		}
		if (lugdet.no_ofluggages != 1) {
			for (int j = 0; j < lugdet.no_ofluggages; j++) {
				outFile << "\nluggage Weight " << j + 1 << " " << lugdet.luggageweight[j] << "kg" << endl;
			}
			outFile << "\nluggage Extra Price $" << extraluggageprice << endl;
		}
	}
	void details()
	{
		cout << CYAN << "\n\n\t\t\t\t\t\tFlights From Islamabad      Departure         Arrival          Status" << RESET;
		cout << YELLOW << "\n\t\t\t\t\t\tIslamabad to Lahore         09:30 AM          10:30 AM         On Time" << RESET;
		cout << GREEN << "\n\t\t\t\t\t\tIslamabad to Karachi        10:45 AM          12:30 PM         On Time" << RESET;
		cout << RED << "\n\t\t\t\t\t\tIslamabad to Peshawar       01:00 PM          01:45 PM         Delayed" << RESET;
		cout << RED << "\n\t\t\t\t\t\tIslamabad to Multan         02:00 PM          03:00 PM         Delayed" << RESET;
		cout << GREEN << "\n\t\t\t\t\t\tIslamabad to Quetta         03:20 PM          04:20 PM         On Time" << RESET;
		cout << RED << "\n\t\t\t\t\t\tIslamabad to Skardu         04:30 PM          05:30 PM         Cancelled" << RESET;
		cout << "\n";
		cout << CYAN << "\n\t\t\t\t\t\tFlights To Islamabad        Departure         Arrival          Status" << RESET;
		cout << GREEN << "\n\t\t\t\t\t\tLahore to Islamabad         09:30 AM          10:30 AM         On Time" << RESET;
		cout << RED << "\n\t\t\t\t\t\tKarachi to Islamabad        10:45 AM          12:30 PM         Delayed" << RESET;
		cout << RED << "\n\t\t\t\t\t\tPeshawar to Islamabad       01:00 PM          01:45 PM         Cancelled" << RESET;
		cout << GREEN << "\n\t\t\t\t\t\tMultan to Islamabad         02:00 PM          03:00 PM         On Time" << RESET;
		cout << RED << "\n\t\t\t\t\t\tQuetta to Islamabad         03:20 PM          04:20 PM         Delayed" << RESET;
		cout << GREEN << "\n\t\t\t\t\t\tSkardu to Islamabad         04:30 PM          05:30 PM         On Time" << RESET;
		cout << "\n";


	}
	void writenottofile(ofstream& file)
	{
		ofstream outFile("Airline management proj.txt", ios::app);
		if (outFile.is_open()) {
			outFile << "\n\t\t\t\tNOTICE BOARD \n";
			outFile << "\n\n\t\tFlights From Islamabad Departure          Arrival         Status";
			outFile << "\n\t\tIslamabad to Lahore    09:30 AM          10:30 AM         On Time";
			outFile << "\n\t\tIslamabad to Karachi   10:45 AM          12:30 PM         On Time";
			outFile << "\n\t\tIslamabad to Peshawar  01:00 PM          01:45 PM         Delayed";
			outFile << "\n\t\tIslamabad to Multan    02:00 PM          03:00 PM         Delayed";
			outFile << "\n\t\tIslamabad to Quetta    03:20 PM          04:20 PM         On Time";
			outFile << "\n\t\tIslamabad to Skardu    04:30 PM          05:30 PM        Cancelled";
			outFile << "\n";
			outFile << "\n\t\tFlights To Islamabad   Departure          Arrival         Status";
			outFile << "\n\t\tLahore to Islamabad    09:30 AM          10:30 AM         On Time";
			outFile << "\n\t\tKarachi to Islamabad   10:45 AM          12:30 PM         Delayed";
			outFile << "\n\t\tPeshawar to Islamabad  01:00 PM          01:45 PM        Cancelled";
			outFile << "\n\t\tMultan to Islamabad    02:00 PM          03:00 PM         On Time";
			outFile << "\n\t\tQuetta to Islamabad    03:20 PM          04:20 PM         Delayed";
			outFile << "\n\t\tSkardu to Islamabad    04:30 PM          05:30 PM         On Time";
			outFile << "\n";

		}
		else
		{
			cerr << "Unable to open file for writing." << endl;
		}

	}
	void check_in() {
		cout << GREEN << "\n\n\t\t\t\t\t\t\t\t| All Documents are valid! Check in Complete |" << RESET;
	}

	void boardingpassgeneration(int i) {
		cout << BLUE << "\n\n\t\t\t\t\t\t\t\t| Passenger details |" << endl;
		cout << "\n\n\t\t\t\t\t\t\t\t| Name: " << passdett.passengerfirstname[i] << " " << passdett.passengerlastname[i] << " |" << RESET;
		cout << "\n\n\t\t\t\t\t\t\t\t| ID: " << passdett.passengerid[i] << " |" << RESET;
		cout << CYAN << "\n\n\t\t\t\t\t\t\t\t| Departure From: Islamabad |" << RESET;

		if (choice == 1) {
			cout << YELLOW << "\n\t\t\t\t\t\t\t\t| To: Lahore |";
			cout << "\n\t\t\t\t\t\t\t\t| Departure Time: 09:30 AM |";
			cout << "\n\t\t\t\t\t\t\t\t| Arrival Time: 10:30 AM |" << RESET;
		}
		else if (choice == 2) {
			cout << YELLOW << "\n\t\t\t\t\t\t\t\t| To: Karachi |";
			cout << "\n\t\t\t\t\t\t\t\t| Departure Time: 10:45 AM |";
			cout << "\n\t\t\t\t\t\t\t\t| Arrival Time: 12:30 PM |" << RESET;
		}
		else if (choice == 3) {
			cout << YELLOW << "\n\t\t\t\t\t\t\t\t| To: Peshawar |";
			cout << "\n\t\t\t\t\t\t\t\t| Departure Time: 01:00 PM |";
			cout << "\n\t\t\t\t\t\t\t\t| Arrival Time: 01:45 PM |" << RESET;
		}
		else if (choice == 4) {
			cout << YELLOW << "\n\t\t\t\t\t\t\t\t| To: Multan |";
			cout << "\n\t\t\t\t\t\t\t\t| Departure Time: 02:00 PM |";
			cout << "\n\t\t\t\t\t\t\t\t| Arrival Time: 03:00 PM |" << RESET;
		}
		else if (choice == 5) {
			cout << YELLOW << "\n\t\t\t\t\t\t\t\t| To: Quetta |";
			cout << "\n\t\t\t\t\t\t\t\t| Departure Time: 03:20 PM |";
			cout << "\n\t\t\t\t\t\t\t\t| Arrival Time: 04:20 PM |" << RESET;
		}
		else if (choice == 6) {
			cout << YELLOW << "\n\t\t\t\t\t\t\t\t| To: Skardu |";
			cout << "\n\t\t\t\t\t\t\t\t| Departure Time: 04:30 PM |";
			cout << "\n\t\t\t\t\t\t\t\t| Arrival Time: 05:30 PM |" << RESET;
		}
		cout << BLUE << "\n\t\t\t\t\t\t\t\t| Flight Number: " << fnit.flightid[i] << " |";
		cout << "\n\t\t\t\t\t\t\t\t| Ticket Number: " << ticdet.ticketIDs[i] << " |" << RESET;
	}

	void writeboard_tofile(ofstream& file, int i)
	{
		ofstream outFile("Airline management proj.txt", ios::app);
		if (outFile.is_open())
		{
			outFile << "\n\n\t\tPassenger details " << passdett.passengerfirstname[i] << "  " << passdett.passengerlastname[i];

			outFile << "\n\n\t\tDeparture From: Islamabad";

			if (choice == 1)
			{
				outFile << "\n\t\tDeparture Time: 09:30 AM ";
				outFile << "\n\t\tTo: Lahore";
				outFile << "\n\t\tArrival Time: 10:30 AM";
			}
			else if (choice == 2)
			{
				outFile << "\n\t\tDeparture Time: 10:45 AM";
				outFile << "\n\t\tTo: Karachi";
				outFile << "\n\t\tArrival Time: 12:30 PM";
			}
			else if (choice == 3)
			{
				outFile << "\n\t\tDepartue Time: 01:00 PM";
				outFile << "\n\t\tTo: Peshawar";
				outFile << "\n\t\tArrival Time: 01:45 PM";
			}
			else if (choice == 4)
			{
				outFile << "\n\t\tDeparture Time: 02:00 PM";
				outFile << "\n\t\tTo: Multan";
				outFile << "\n\t\tArrival Time: 03:00 PM";
			}
			else if (choice == 5)
			{
				outFile << "\n\t\tDeparture Time: 03:20 PM";
				outFile << "\n\t\tTo: Quetta";
				outFile << "\n\t\tArrival Time: 04:20 PM";
			}
			else if (choice == 6)
			{
				outFile << "\n\t\tDeparture Time: 04:30 PM";
				outFile << "\n\t\tTo: Skardu:";
				outFile << "\n\t\tArrival Time: 05:30 PM";

				outFile << "\n\t\tFlight Number: " << fnit.flightid[i];
				outFile << "\n\t\tTicket Number:" << ticdet.ticketIDs[i];
			}
		}
	}

void mainmen() {
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
	cout << YELLOW << " __________________________________________________________________________________________________________________________________________________________" << RESET << endl;
	cout << YELLOW << "|________________________________________________________________ISLAMABAD AIRLINES________________________________________________________________________|" << RESET << endl;
	cout << YELLOW << "|__________________________________________________________________________________________________________________________________________________________|" << RESET << endl << endl;
	cout << YELLOW << " __________________________________________________________________________________________________________________________________________________________ " << RESET << endl;
	cout << YELLOW << "|______________________________________________________________________MAIN MENU___________________________________________________________________________|" << RESET << endl;
	cout << YELLOW << "|__________________________________________________________________________________________________________________________________________________________|" << RESET << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
}

void displayboard() {
	cout << CYAN << "\n\n\t\t\t\t\t\t\t\t|1. FLIGHT BOOKING         |" << RESET << endl;
	cout << CYAN << "\t\t\t\t\t\t\t\t|2. LUGGAGE DETAILS        |" << RESET << endl;
	cout << CYAN << "\t\t\t\t\t\t\t\t|3. SEAT RESERVATION       |" << RESET << endl;
	cout << CYAN << "\t\t\t\t\t\t\t\t|4. TICKET DETAILS         |" << RESET << endl;
	cout << CYAN << "\t\t\t\t\t\t\t\t|5. VIEW NOTICEBOARD       |" << RESET << endl;
	cout << CYAN << "\t\t\t\t\t\t\t\t|6. CHECK-IN AND BOARDING  |" << RESET << endl;
	cout << CYAN << "\t\t\t\t\t\t\t\t|7. SAVE INFORMATON        |" << RESET << endl;
	cout << CYAN << "\t\t\t\t\t\t\t\t|8. CHANGE LOGIN ID/PASS   |" << RESET << endl;
	cout << CYAN << "\t\t\t\t\t\t\t\t|9. EXIT OR ENTER NEXT     |" << RESET << endl;
	cout << CYAN << "\t\t\t\t\t\t\t\t|   PASSENGER DETAILS      |" << RESET << endl;
}


// seat reservation 

const int ROWS = 8;
const int COLUMNS = 6;

void initializeSeats(char seats[ROWS][COLUMNS]) {
	srand(time(0));
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMNS; ++j) {
			seats[i][j] = (rand() % 2 == 0) ? '_' : 'X';  // Randomly assign '_' or 'X'
		}
	}
}

void displaySeats(const char seats[ROWS][COLUMNS]) {
	cout << CYAN << "\n\n\t\t\t\t\t\t\tFOLLOWING ARE THE RESERVED AND AVAILABLE SEATS\n\n" << RESET << endl;
	cout << CYAN << "\t\t\t\t\t\t\t\t" << "  A B C D E F\n" << RESET;
	for (int i = 0; i < ROWS; ++i) {
		cout << CYAN << "\t\t\t\t\t\t\t\t" << i + 1 << " " << RESET;
		for (int j = 0; j < COLUMNS; ++j) {
			cout << CYAN << seats[i][j] << " " << RESET;
		}
		cout << endl;
	}
}

void displayAvailableSeats(const char seats[ROWS][COLUMNS]) {
	cout << CYAN << "\n\n\t\t\t\t\t\t\t\t" << "AVAILABLE SEATS:\n\n" << RESET;
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMNS; ++j) {
			if (seats[i][j] == '_') {
				cout << CYAN << "\t\t\t\t\t\t\t\t" << "ROW " << i + 1 << " SEAT " << char('A' + j) << RESET << endl;
			}
		}
	}
}

int row;
char column;
string nseat;
void reserveSeat(char seats[ROWS][COLUMNS]) {

selectseatagain:
	cout << GREEN << "\n\t\t\t\t\t\t\t\t" << "ENTER ROW NUMBER (1-" << ROWS << "): " << RESET;
	cin >> row;
	cout << GREEN << "\n\t\t\t\t\t\t\t\t" << "ENTER SEAT COLUMN (A-D): " << RESET;
	cin >> column;
	int colindex = column - 'A';

	if (row < 1 || row > ROWS || colindex < 0 || colindex >= COLUMNS) {
		cout << RED << "\t\t\t\t\t\t\t\t" << "INVALID SEAT SELECTION.SELECT THE SEAT AGAIN\n" << RESET;
		goto selectseatagain;
	}

	if (seats[row - 1][colindex] == 'X') {
		cout << RED << "\t\t\t\t\t\t\t\t" << "SEAT IS ALREADY RESERVED.\n" << RESET;
		goto selectseatagain;
	}

	seats[row - 1][colindex] = 'X';
	cout << GREEN << "\t\t\t\t\t\t\t\t" << "SEAT " << row << column << " RESERVED SUCCESSFULLY.\n" << RESET;
	nseat = to_string(row) + column;
}

void writeseat_reservation_tofile(ofstream& file)
{
	ofstream outFile("Airline management proj.txt", ios::app);
	if (outFile.is_open())
	{
			outFile << "\n\n\t\tSEAT " << nseat << " RESERVED SUCCESSFULLY.\n" << endl;
	}
}




char seats[ROWS][COLUMNS];
int main()
{
	cout << YELLOW << " __________________________________________________________________________________________________________________________________________________________" << RESET << endl;
	cout << YELLOW << "|________________________________________________________________ISLAMABAD AIRLINES________________________________________________________________________|" << RESET << endl;
	cout << YELLOW << "|__________________________________________________________________________________________________________________________________________________________|" << RESET << endl << endl<<endl;
	cout <<CYAN<< "\t   _______" << endl;
	cout << CYAN << "\t  ||      \\\\" << endl;
	cout << CYAN << "\t  ||       \\\\" << endl;
	cout << CYAN << "\t  ||        \\\\" << endl;
	cout << CYAN << "\t  ||         \\\\" << endl;
	cout << CYAN << "\t  ||          \\\\" << endl;
	cout << CYAN << "\t  ||           \\\\" << endl;
	cout << CYAN << "\t  ||            \\\\" << endl;
	cout << CYAN << "\t  ||_____________\\\\_________________________________________________________________________________________________" << endl;
	cout << CYAN << "\t //                                                  /                            \\                               /\\\\" << endl;
	cout << CYAN << "\t ||                                                 /                              \\                             /__\\\\_______" << endl;
	cout << CYAN << "\t ||    _________________                           /                                \\                                       \\\\ " << endl;
	cout << CYAN << "\t \\\\    \\______          \\                          | WELCOME TO ISLAMABAD   AIRLINE |                                        \\\\" << endl;
	cout << CYAN << "\t  \\\\          \\__________\\                         \\                                /                                        /\\\\" << endl;
	cout << CYAN << "\t    \\\\                                              \\                      ______  /                                         \\//" << endl;
	cout << CYAN << "\t     \\\\______________________________________________\\____________________/______|/__________________________________________//" << endl;
	cout << CYAN << "\t                                                                          \\______|                                               " << endl<<endl<<endl;
	cout << YELLOW << " __________________________________________________________________________________________________________________________________________________________ " << RESET << endl;
	cout << YELLOW << "|______________________________________________________________________MAIN MENU___________________________________________________________________________|" << RESET << endl;
	cout << YELLOW << "|__________________________________________________________________________________________________________________________________________________________|" << RESET << endl;
	srand(time(0));
	int num;
	int option;
	string key;
	
	login();
	cout << endl << endl;
reenterpassengernumber:
	cout << GREEN << "\n\t\t\t\t\t\t\t\t ENTER THE NUMBER OF PASSENGERS: " << RESET;

	cin >> num;
	if (num > 5) {
		cout << RED << "\n\n\t\t\t\t\t\t\t PASSENGER LIMIT EXCEEDING!!!MAXIMUM PASSENEGERS ALLOWED ARE 5!!!  " << RESET << endl;
		cout << RED << "\n\n\t\t\t\t\t\t\t RE-ENTER THE NUMBER OF PASSENGER!!!  " << RESET << endl;
		goto reenterpassengernumber;
	}
	initializeSeats(seats);
	for (int i = 0; i < num; i++)
	{
		do
		{
			system("cls");
			mainmen();
			cout << YELLOW << "\t\t\t\t\t\t\t\t ENTER DETAILS OF PASSENGER : " << i + 1 << RESET << endl;
			displayboard();
			cout << endl;
			cout << YELLOW << "\t\t\t\t\t\t\t\t ENTER YOUR CHOICE: " << RESET;
			cin >> option;
			switch (option)
			{
			case 1:
			{
				putdetails(i); // Get passenger details
				displaypassengerdetails(i);


				break;
			}
			case 4:
			{
				flights(i); // Select flight and display confirmation
				addtickets(i); // Add ticket details
				displaytickets(i,nseat); // Display ticket details
				break;
			}
			case 2:
			{
				luggagedetails(i);  // Get luggage details
				break;
			}
			case 3:
			{
				cout << GREEN << "\n\t\t\t\t\t\t\t\t||  SEAT RESERVATION  ||" << RESET;

					displaySeats(seats);     //  shows total number of seats in form of rows and columns
					displayAvailableSeats(seats);    // displays the seats that are available in row and (A-F) columns
					reserveSeat(seats);
					
				break;
			}
			case 5:
			{
				details(); // Display noticeboard details
				break;
			}
			case 6:
			{
				check_in(); // Perform check-in
			    boardingpassgeneration(i); // Generate boarding pass
				break;
			}
			case 7:
			{
				ofstream file("Airline management proj.txt", ios::app);
				{
					writeairdetails();
				    writepastofile(file, i);
					writeflighttofile(file, i);
					writelugtofile(file, i);
					writeseat_reservation_tofile(file);
					writeticktofile(file, i);
					writenottofile(file);
					writeboard_tofile(file, i);
					file << endl;
				}
				file.close();
				break;
			}
			case 8:
			{
				int choose;
				cout << GREEN << "\n\n\t\t\t\t\t\t\tPRESS 1 TO CHANGE LOGIN ID OR PRESS 2 TO CHANGE LOGIN PASSWORD:  " << RESET ;
				cin >> choose;
				if (choose == 1) {
					cout << GREEN << "\n\n\t\t\t\t\t\t\tENTER NEW LOGIN ID:  "<<RESET;
					ofstream writeid("id.txt", ios::out);
					char newid[10];
					cin >> newid;
					writeid << newid;
					writeid.close();
				}
				else {
					cout << GREEN << "\n\n\t\t\t\t\t\t\tENTER NEW LOGIN PASSWORD:  "<<RESET;
					ofstream writepass("pass.txt", ios::out);
					char newpass[10];
					cin >> newpass;
					writepass << newpass;
					writepass.close();
				}
				break;
			}

			case 9:
			{
				if (i > 1) {
					goto nextpass;
				}
				else {
					cout << GREEN << "\n\n\t\t\t\t\t\t\tTHANK YOU FOR CHOOSING ISLAMABAD AIRLINES" << RESET << endl;
					cout << GREEN << "\n\n\t\t\t\t\t\t\t\tWE HOPE TO SEE YOU AGAIN\n\n" << RESET << endl;
					goto exite;
				}
				break;

			}
			default:
				cout << "\t\t\t\t\t\t\t\t Invalid choice. Please try again.\n";
				break;
			}
		nextpass:
			cout << "\n\t\t\t\t\t\t\t\t Press any key and enter to continue....";
			cin >> key;
		exite:
			cout << endl;
		} while (option != 9);

		cout << endl;
	}

	_getch;
	return 0;
}