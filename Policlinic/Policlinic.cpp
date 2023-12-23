//#include <random> 
#include <string> 
#include <iomanip> 
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <ios>
#include <fstream>
#include <iostream> 
#include <vector>
#include "Patients.h"
#include "Doctors.h"
#include "Services.h"
#include "Controllers.h"
//#include <Windows.h>
//#include <io.h>
//#include <fcntl.h>
using namespace std;


int main()
{
	Controllers* controller = new Controllers();
	controller->Menu();
}

