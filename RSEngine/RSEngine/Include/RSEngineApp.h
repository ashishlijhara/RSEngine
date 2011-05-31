#ifndef _RSENGINEAPP_H_
#define _RSENGINEAPP_H_

#include "RSEngineApp.h"
#include "IBaseEngineApp.h"
#include "RSDefs.h"


namespace RSE{
	class RSApplicationLayer;
	class RSGameLogicLayer;
	class RSEngineApp:public IBaseEngineApp{

	public:
		/*
		* Default CTor.
		*/
		RSEngineApp(){}

		/*
		* DTor
		*/
		~RSEngineApp(){
		}

		/*
		*	VInit handles initializing the Game App and is called by CEngineApp after initializing Ogre and the Game engine.
		*	The VInit function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		const FResult VInit();

		/*
		*	VUpdate handles updating the RSGameViews and RSGameLogic Layers definde in the Game App and is called EngineApp after updating Ogre and the Game engine.
		*	The VUpdate function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		const FResult VUpdate(const float &delTime);

		/*
		*	VPause handles pausing or unpausing the Game App and indicating the same game state to the EngineApp.
		*	The VPause function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		const FResult VPause(const bool &pause);

		/*
		*	VEnd handles ending the Game App and is called EngineApp before ending the Ogre and the Game engine operations.
		*	The VEnd function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		const FResult VEnd();

		/*
		*	VCleanup handles cleans up the Game App and is called EngineApp before cleaning up Ogre and the Game engine.
		*	The VCleanup function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		const FResult VCleanup();

	private:
		RSApplicationLayer *m_pRSApplicationLayer;
		RSGameLogicLayer *m_pRSGameLogicLayer;
	};
}

#endif