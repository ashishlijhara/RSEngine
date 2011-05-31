#include <iostream>
#include <conio.h>
#include "RSDefs.h"
#include "RSEngineApp.h"
#include "boost\shared_ptr.hpp"

using namespace RSE;

int main(int argv, char * argc[]){

	FResult result;
	memset(&result,0,sizeof(result));

	boost::shared_ptr<RSEngineApp> engineApp(new RSEngineApp());

	result = engineApp.get()->VInit();
	if(result.m_Result == ORESULT_ERROR){
		std::cout<<result.m_pcDescription;
		return -1;
	}

	while(1){
		result = engineApp.get()->VUpdate(5);
		if(result.m_Result == ORESULT_ERROR){
			std::cout<<result.m_pcDescription;
			return -1;
		}
	}

	result = engineApp.get()->VEnd();
	if(result.m_Result == ORESULT_ERROR){
		std::cout<<result.m_pcDescription;
		return -1;
	}

	result = engineApp.get()->VCleanup();
	if(result.m_Result == ORESULT_ERROR){
		std::cout<<result.m_pcDescription;
		return -1;
	}
	

	return 0;
}