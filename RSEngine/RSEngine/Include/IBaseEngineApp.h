#ifndef _IBASEAPP_H_
#define _IBASEAPP_H_

#include "RSdefs.h"
#include "RSUncopyable.h"

namespace RSE{
	class IBaseEngineApp:Uncopyable{
	public:
		/*
		*	CTor for IBaseApp.
		*/
		IBaseEngineApp(){}

		/*
		*	DTor for IBaseApp.
		*/
		virtual ~IBaseEngineApp(){}
		
		/*
		*	VInit handles initializing the Game App and is called by RSEngineApp after initializing Ogre and the Game engine.
		*	The VInit function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		virtual const FResult VInit() = 0;

		/*
		*	VUpdate handles updating the RSGameViews and RSGameLogic Layers definde in the Game App and is called RSEngineApp after updating Ogre and the Game engine.
		*	The VUpdate function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		virtual const FResult VUpdate(const float &delTime) = 0;

		/*
		*	VPause handles pausing or unpausing the Game App and indicating the same game state to the RSEngineApp.
		*	The VPause function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		virtual const FResult VPause(const bool &pause) = 0;

		/*
		*	VEnd handles ending the Game App and is called RSEngineApp before ending the Ogre and the Game engine operations.
		*	The VEnd function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		virtual const FResult VEnd() = 0;

		/*
		*	VCleanup handles cleans up the Game App and is called RSEngineApp before cleaning up Ogre and the Game engine.
		*	The VCleanup function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		virtual const FResult VCleanup() = 0;
	};
}

#endif