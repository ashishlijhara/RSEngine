#ifndef _RSOGREHANDLER_H_
#define _RSOGREHANDLER_H_

#include "RSDefs.h"
#include "IOgreHandler.h"
#include "Ogre\Ogre.h"
#include "IBaseGameApp.h"

using namespace Ogre;

namespace RSE{

	class RSOgreHandler:public IOgreHandler, public Ogre::Singleton<RSOgreHandler>{
	private:
		Root *m_pRSRoot;
		RenderWindow *m_pRSRenderWindow;
		Viewport *m_pRSViewport;

		IBaseGameApp *m_pBaseGameApp;

		bool m_bPaused;

	protected:

		void InitOgreRoot();

		void InitRenderWindow(String title);

		void LoadOgreResources(const int &iDefaultNumMipMaps = 5);

	public:

		static RSOgreHandler& getSingleton(void);
		static RSOgreHandler* getSingletonPtr(void);

		/*
		* CTor
		*/
		RSOgreHandler();

		/*
		* DTor
		*/
		virtual ~RSOgreHandler();

		/*
		*	VInitOgre handles initializing Ogre and initializes rendering.
		*	The VInitOgre function is a pure virtual function from IOgreHandler and is implemented in this class.
		*	It should return an object if FResult.
		*/
		const FResult VInitOgre(const bool &bShowConfigDialog=true, String sWindowTitle = DefaultWindowTitle);

		/*
		*	VUpdateOgre handles updating Ogre.
		*	The VUpdateOgre function is a pure virtual function from IOgreHandler and is implemented in this class.
		*	It should return an object if FResult.
		*/
		const FResult VUpdateOgre(const float &delTime);

		/*
		*	VPauseOgre handles pausing and unpausing rendering with Ogre.
		*	The VPauseOgre function is a pure virtual function from IOgreHandler and is implemented in this class.
		*	It should return an object if FResult.
		*/
		const FResult VPauseOgre(const bool &paused);

		/*
		*	VEndOgre ends rendering with Ogre.
		*	The VEndOgre function is a pure virtual function from IOgreHandler and is implemented in this class.
		*	It should return an object if FResult.
		*/
		const FResult VEndOgre();

		/*
		*	VCleanupOgre cleans up Ogre and related objects.
		*	The VCleanupOgre function is a pure virtual function from IOgreHandler and is implemented in this class.
		*	It should return an object if FResult.
		*/
		const FResult VCleanupOgre();

		/*
		*	VShowConfigDialog displays the config dialog box if required.
		*	The VShowConfigDialog function is a pure virtual function from IOgreHandler and has been implemented in this class.
		*	It should return an object if FResult.
		*/
		const void VShowConfigDialog(const bool& value);

		const FResult VSetBaseGameApp(IBaseGameApp *app);


		const IBaseGameApp* VGetBaseGameApp() const;


		Root*const GetRSRoot() const;

		void SetRSRoot(Root* pRoot);

		RenderWindow * GetRenderWindow() const;

		Viewport* GetViewport() const;

		void SetViewPort(Viewport *pViewport);
	};
}

#endif