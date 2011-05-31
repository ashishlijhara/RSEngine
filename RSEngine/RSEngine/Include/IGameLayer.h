#ifndef _IGAMELAYER_H_
#define _IGAMELAYER_H_

#include "RSDefs.h"

namespace RSE{
	class IGameLayer{
	public:
		/*
		* CTor
		*/
		IGameLayer(){}
		
		/*
		* DTor
		*/
		virtual ~IGameLayer(){}

		
		virtual FResult VInit()=0;

		
		virtual FResult VUpdate(const float &delTime)=0;

		
		virtual FResult VShutdown()=0;
	};
}

#endif