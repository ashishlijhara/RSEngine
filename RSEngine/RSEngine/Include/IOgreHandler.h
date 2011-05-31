#ifndef _IOGREHANDLER_H_
#define _IOGREHANDLER_H_

#include "RSEngine.h"
#include "IBaseGameApp.h"
namespace RSE{
	class IOgreHandler:Uncopyable{
	public:
		/*
		* CTor.
		*/
		IOgreHandler(){}

		/*
		* DTor
		*/
		virtual ~IOgreHandler() {}


		/*
		*	VInitOgre handles initializing Ogre and initializes rendering.
		*	The VInitOgre function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		virtual const FResult VInitOgre(const bool &bShowConfigDialog=true, String sWindowTitle = DefaultWindowTitle) = 0;

		/*
		*	VUpdateOgre handles updating Ogre.
		*	The VUpdateOgre function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		virtual const FResult VUpdateOgre(const float &delTime) = 0;

		/*
		*	VPauseOgre handles pausing and unpausing rendering with Ogre.
		*	The VPauseOgre function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		virtual const FResult VPauseOgre(const bool &paused) = 0;

		/*
		*	VEndOgre ends rendering with Ogre.
		*	The VEndOgre function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		virtual const FResult VEndOgre() = 0;
		
		/*
		*	VCleanupOgre cleans up Ogre and related objects.
		*	The VCleanupOgre function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		virtual const FResult VCleanupOgre() = 0;

		/*
		*	VShowConfigDialog displays the config dialog box if required.
		*	The VShowConfigDialog function is a pure virtual function and has to implemented in the classes that derive from IBaseApp.
		*	It should return an object if FResult.
		*/
		virtual const void VShowConfigDialog(const bool& value) = 0;


		virtual const FResult VSetBaseGameApp(IBaseGameApp *app) = 0;


		virtual const IBaseGameApp* VGetBaseGameApp() const = 0;
	};
};
#endif