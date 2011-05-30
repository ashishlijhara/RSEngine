#include "RSOgreHandler.h"
#include "CheckGameApp.h"

template<> RSE::RSOgreHandler* Ogre::Singleton<RSE::RSOgreHandler>::ms_Singleton = 0;

namespace RSE{
	
	RSOgreHandler* RSOgreHandler::getSingletonPtr(void)
	{
		return ms_Singleton;
	}
	RSOgreHandler& RSOgreHandler::getSingleton(void)
	{  
		assert( ms_Singleton );  
		return ( *ms_Singleton );  
	}

	RSOgreHandler::RSOgreHandler():m_bPaused(false){
		
	}


	RSOgreHandler::~RSOgreHandler(){
	
	}

	const FResult RSOgreHandler::VInitOgre(const bool &bShowConfigDialog, String sWindowTitle){
		FResult returnResult;
		memset(&returnResult, 0,sizeof(FResult));

		InitOgreRoot();

		if(bShowConfigDialog){
			if(!m_pRSRoot->showConfigDialog())
			{
				SetError(&returnResult, "Error Displaying Ogre Config Dialog");
				return returnResult;
			}
		}

		InitRenderWindow(sWindowTitle);

		m_pRSViewport = m_pRSRenderWindow->addViewport(0);
		m_pRSViewport->setBackgroundColour(ColourValue(0.0f,0.0f,0.0f));
		m_pRSViewport->setCamera(0);

		LoadOgreResources();

		m_pBaseGameApp = dynamic_cast<IBaseGameApp*>(new Check::CheckGameApp());
		m_pBaseGameApp->VInit();

		m_pRSRenderWindow->setActive(true);

		return returnResult;
	}

	void RSOgreHandler::InitOgreRoot(){
		m_pRSRoot = new Root();
	}

	void RSOgreHandler::InitRenderWindow(String title){
		m_pRSRenderWindow = m_pRSRoot->initialise(true,title);
	}

	void RSOgreHandler::LoadOgreResources(const int &iDefaultNumMipMaps){

#pragma region Load The Resources
		String sSecName, sTypeName, sArchName;
		ConfigFile cf;
		cf.load("resources.cfg");

		ConfigFile::SectionIterator seci = cf.getSectionIterator();
		while(seci.hasMoreElements()){
			sSecName = seci.peekNextKey();
			ConfigFile::SettingsMultiMap *settings = seci.getNext();
			ConfigFile::SettingsMultiMap::iterator i;
			for(i = settings->begin(); i != settings->end();++i){
				sTypeName = i->first;
				sArchName = i->second;
				ResourceGroupManager::getSingleton().addResourceLocation(sArchName, sTypeName, sSecName);
			}
		}
#pragma endregion

#pragma region Cache/Init The Resources
		TextureManager::getSingleton().setDefaultNumMipmaps(5);
		ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
#pragma endregion

		//m_pRSRoot->startRendering();
	}

	const FResult RSOgreHandler::VUpdateOgre(const float &delTime){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		assert(m_pBaseGameApp);

		
		WindowEventUtilities::messagePump();
		m_pRSRoot->renderOneFrame();

		returnResult = (m_bPaused)?(m_pBaseGameApp->VRenderPaused()):(m_pBaseGameApp->VRender());

		returnResult = m_pBaseGameApp->VUpdate(delTime);

		return returnResult;
	}

	const FResult RSOgreHandler::VPauseOgre(const bool &paused){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		m_bPaused = paused;
		m_pBaseGameApp->VSetPaused(paused);

		return returnResult;
	}

	const FResult RSOgreHandler::VEndOgre(){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));


		return returnResult;
	}

	const FResult RSOgreHandler::VCleanupOgre(){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		//Don't change the order
		m_pBaseGameApp->VCleanup();
		if(!Release(m_pBaseGameApp)){
			assert(m_pBaseGameApp);
			SetError(&returnResult, "Unable to release Base Game App Object");
		}

		if(!Release(m_pRSRoot))
		{
			assert(m_pRSRoot);
			SetError(&returnResult, "Unable to release root");
		}

		

		return returnResult;
	}

	const void RSOgreHandler::VShowConfigDialog(const bool& value){
		m_bPaused = value;
	}

	const FResult RSOgreHandler::VSetBaseGameApp(IBaseGameApp *app){
		FResult returnResult;
		memset(&returnResult,0,sizeof(FResult));

		assert(app);
		m_pBaseGameApp = app;
		m_pBaseGameApp->VInit();

		return returnResult;
	}


	const IBaseGameApp* RSOgreHandler::VGetBaseGameApp() const{
		return m_pBaseGameApp;
	}

	Root*const RSOgreHandler::GetRSRoot() const{
		return m_pRSRoot;
	}

	RenderWindow* RSOgreHandler::GetRenderWindow() const{
		return m_pRSRenderWindow;
	}

	void RSOgreHandler::SetRSRoot(Root* pRoot){
		m_pRSRoot = pRoot;
	}

	Viewport* RSOgreHandler::GetViewport() const{
		assert(m_pRSViewport);
		return m_pRSViewport;
	}

	void RSOgreHandler::SetViewPort(Viewport *pViewport){
		assert(pViewport);
		m_pRSViewport = pViewport;
	}
}