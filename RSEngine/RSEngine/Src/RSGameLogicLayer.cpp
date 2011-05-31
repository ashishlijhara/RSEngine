#include "RSGameLogicLayer.h"

namespace RSE{
	FResult RSGameLogicLayer::VInit(){
		FResult returnResult;
		memset(&returnResult,0, sizeof(FResult));

		return returnResult;
	}

		
	FResult RSGameLogicLayer::VUpdate(const float &delTime){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));

		return returnResult;
	}

		
	FResult RSGameLogicLayer::VShutdown(){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));

		return returnResult;
	}
}