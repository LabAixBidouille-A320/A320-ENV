#include "Skardll.h"
#include <sstream>
#include <string.h>


using namespace std;

int LEDsa[5000];
int nLEDsa[5000];
int counter = 0;



char* __stdcall License(char* key)
{
	log_PROC("LICENSE, param ", key);
	string s = "3109302";//put here your own license serial, this one won't work obviously...
	char ss[37];
	
	char str[2];
	str[0] = ss[37];
	str[1] = '\0';

	log_PROC("Valeur de ss[37] ", str);


	int a;
	for (unsigned i = 0; i < s.length(); i++)
	{
		a = s[i] + key[i % strlen(key)] - 65;
		ss[i] = a;
		//log_PROC("Valeur de ss[i] chaque itération :", );
	}
	ss[36] = 0;
	return &ss[0];//enciphered serial number
}



int __stdcall Start(PCHAR RootPath)
{
	log_PROC("START, param ", RootPath);
	return 1; // succesful //desire update frequency(bigger the value, slower the update freq)
}

int __stdcall Close(int pnil/*= null pointer*/)
{
	log_PROC("CLOSE", "");
	return 2; // succesful //not used for the moment
}


int __stdcall GetSwitchProc(TSW_PROC* proc)
{
	log_PROC("GETSWITCHPROC","");
	SW_PROC = proc;
	return 3; // succesful
}


int __stdcall LEDs(int LED, int State)//called every cycle, cycle freq définie dans le return de start()
{
	
	stringstream tmpstrs;
	tmpstrs << LED;

	stringstream tmpstrs2;
	tmpstrs2 << State;

	string tmpstr = " LEDid = " + tmpstrs.str();
	tmpstr.append(" State = " + tmpstrs.str());
	
	char* chartemp = (char*)tmpstr.c_str();

	log_PROC("LED, params", chartemp);

	stringstream strs;
	strs << LED;
	string temp_str = "ID:" + strs.str();

	stringstream strs2;
	strs2 << State;
	temp_str.append("  State:");
	temp_str.append(strs2.str());
	char* char_type = (char*)temp_str.c_str();

	bool proceed = true;

	if (LED >= 0) {

		////////////
		/*tmpstr = " " + LEDsa[LED];
		chartemp = (char*)tmpstr.c_str();
		log_PROC("if (LED >= 0) :", chartemp);*/
		////////////

		proceed = (LEDsa[LED] != State);
		LEDsa[LED] = State;
	}
	if (LED < 0) {

		////////////
		/*tmpstr = " " + LEDsa[-LED];
		chartemp = (char*)tmpstr.c_str();
		log_PROC("if (LED < 0) :", chartemp);*/
		////////////

		proceed = (nLEDsa[-LED] != State);
		nLEDsa[-LED] = State;
	}

	
	
	if (proceed) {//if(nLEDsa[+-LED] != State)
		//log_PROC("nLEDsa[+-LED] != State", "VRAI");
		log_PROC("Cmodule", char_type);
	}

	return 4; // succesful
}


int __stdcall TestLEDs(BOOL bln)
{

	log_PROC("TESTLEDS", " ");
	if(bln)
		log_PROC("Paramètres : ", "TRUE");
	else
		log_PROC("Paramètres : ", "FALSE");
	return 5; // succesful
}


int __stdcall GetLogProc(Tlog_PROC* proc)
{
	log_PROC = proc;
	log_PROC("GETLOGPROC", " ");

	return 6; // succesful
}


int __stdcall FastTimer(void)
{


	log_PROC("FASTIMER", "");

	if (counter == 100) {
		SW_PROC(7, API_SW_DN);
		log_PROC("Cmodule", "SW:7 Dir:API_SW_DN");
	}
	if (counter == 200) {
		SW_PROC(7, API_SW_UP);
		log_PROC("Cmodule", "SW:7 Dir:API_SW_UP");
		counter = 0;
	}
	counter++;
	return 7; // succesful
}


/*
char* __stdcall GetAnalogProc(Tanalog_PROC* analogProc) {

	return //ModuleName is a pansichar containing the same module name as you registered when returning the GetAnalogProc call.
}
*/
//int __stdcall StringData(int dataCode, char* text /*PANSICHAR*/) {

//}

